import sys
input = sys.stdin.readline

MOD = 10 ** 9 + 7
N = 2000
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
        return fact[n] * invfact[k] * invfact[n - k] % MOD

def main():
    n, x, pos = map(int, input().split())
    b = 0
    s = 0
    l = 0
    r = n
    while l < r:
        m = (l + r) // 2
        if m <= pos:
            l = m + 1
            if m != pos:
                s += 1
        else:
            r = m
            if m != pos:
                b += 1
        
    b_cnt = n - x
    s_cnt = x - 1
    c = n - 1 - b - s
    ans = fact[c] * nCk(b_cnt, b) * nCk(s_cnt, s) * fact[b] * fact[s]
    print(ans % MOD)
    
for _ in range(1):
    main()