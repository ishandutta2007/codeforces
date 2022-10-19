import sys
input = sys.stdin.readline
from collections import defaultdict
MOD = 998244353
N = 200000

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
    n = int(input())
    S = input().strip()
    c1 = 0
    c2 = 0
    cnt = 0
    for s in S:
        if s == "1":
            cnt += 1
        else:
            c1 += cnt // 2
            c2 += cnt % 2
            cnt = 0
    c1 += cnt // 2
    c2 += cnt % 2
    print(nCk(n - c1 - c2, c1))
            
                
    
    
for _ in range(int(input())):
    main()