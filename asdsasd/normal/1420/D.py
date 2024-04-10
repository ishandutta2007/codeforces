import sys
input = sys.stdin.readline

MOD = 998_244_353
N = 3 * 10 ** 5 + 10

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
    n, k = map(int, input().split())
    l_s = []
    r_s = []
    for _ in range(n):
        l, r = map(int, input().split())
        l_s.append(l)
        r_s.append(r)
    l_s.sort()
    r_s.sort()
    l_pos = 0
    r_pos = 0
    total = 0
    ans = 0
    while 1:
        if l_s[l_pos] <= r_s[r_pos]:
            total += 1
            l_pos += 1
            if total >= k:
                ans += nCk(total - 1, k - 1)
                ans %= MOD
            if l_pos == n:
                break
        else:
            total -= 1
            r_pos += 1

    print(ans)
        
    
    
"""
for _ in range(int(input())):
    main()
"""
main()