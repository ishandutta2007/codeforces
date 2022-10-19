import sys
input = sys.stdin.readline
MOD = 10 ** 9 + 7
N = 10000
fact = [0 for _ in range(N)]
invfact = [0 for _ in range(N)]
fact[0] = 1
for i in range(1, N):
    fact[i] = fact[i - 1] * i % MOD

invfact[N - 1] = pow(fact[N - 1], MOD - 2, MOD)

for i in range(N - 2, -1, -1):
    invfact[i] = invfact[i + 1] * (i + 1) % MOD

def nCk(n, k):
    if k < 0 or n < k:
        return 0
    else:
        return (fact[n] * invfact[k] % MOD) * invfact[n - k] % MOD

def nHk(n, k):
    return nCk(n + k - 1, k)


def main():
    n, l, r, z = map(int, input().split())
    bit = [0] * 60
    for i in range(60):
        if z >> i & 1:
            bit[i] = 1
            r -= 1 << i
            l -= 1 << i
    if r < 0:
        print(0)
        return
    
    ma = [0] * 60
    for i in range(60):
        if n % 2 == bit[i]:
            nn = n
        else:
            nn = n - 1
        ma[i] = (1 << (i + 1)) * nn
        if i != 0:
            ma[i] += ma[i - 1]

    tot = [0] * 60
    for i in range(60):
        for j in range(bit[i], n + 1, 2):
            tot[i] += nCk(n, j)
            tot[i] %= MOD
        if i != 0:
            tot[i] *= tot[i - 1]
            tot[i] %= MOD

    memo = {}
    d = r - l
    bi = [1 << i for i in range(61)]

    def solve(i, l):
        r = l + d
        if l <= 0 and ma[i] <= r:
            return tot[i]
        elif ma[i] < l:
            return 0
        elif i == -1:
            return l <= 0
        elif i + 60 * l in memo:
            return memo[i + 60 * l]
        
        ret = 0
        mi = bi[i + 1]
        ll = l
        rr = r
        for j in range(bit[i], n + 1, 2):
            ret += solve(i - 1, ll) * nCk(n, j) % MOD
            if ret >= MOD: ret -= MOD
            ll -= mi
            rr -= mi
            if rr < 0:
                break

        memo[i + 60 * l] = ret
        return ret
    
    ans = solve(59, l)
    
    print(ans)
    
    
for _ in range(1):
    main()