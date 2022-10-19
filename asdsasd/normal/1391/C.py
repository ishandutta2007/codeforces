import sys
input = sys.stdin.readline

MOD = 10 ** 9 + 7

N = 10 ** 6 + 10

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
    n = int(input())
    ans = fact[n]
    for i in range(n):
        ans -= nCk(n - 1, i)
        ans %= MOD
    print(ans)

"""
for _ in range(int(input())):
    main()
"""
main()