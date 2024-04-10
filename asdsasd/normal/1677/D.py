import sys
input = sys.stdin.readline

MOD = 998244353
N = 1000100
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
    n, k = map(int, input().split())
    V = list(map(int, input().split()))
    for i in range(n - 1, n - k - 1, -1):
        if V[i] == -1:
            V[i] = 0
        if V[i] != 0:
            print(0)
            return
    if V[0] == -1:
        V[0] = 0
    if V[0] != 0:
        print(0)
        return

    times = 1
    for i in range(1, k + 2):
        times *= i
        times %= MOD
    zero = [0] * (n + 1)
    zero[k + 1] = times
    for i in range(k + 2, n + 1):
        zero[i] = zero[i - 1] * (k + 1) % MOD
    
    z = 0
    ans = 1
    for i, v in enumerate(V):
        if v == 0:
            z += 1
        elif v == -1:
            ans *= (k + 1) + i
            ans %= MOD
        
    
    ans *= zero[z]
    print(ans % MOD)

    
for _ in range(int(input())):
    main()