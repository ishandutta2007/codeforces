import sys
input = sys.stdin.readline

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
    S = [list(input().strip()) for _ in range(n)]
    minus = 1
    cnt = [[0] * 3 for _ in range(2)]
    for i in range(n):
        if S[i][1] == "B":
            S[i][1] = "W"
        elif S[i][1] == "W":
            S[i][1] = "B"
        
        if S[i] == ["?", "?"]:
            minus *= 2
            minus %= MOD
        elif "?" in S[i]:
            pass
        elif S[i][0] != S[i][1]:
            minus = 0
        
        for j in range(2):
            if S[i][j] == "B":
                cnt[j][0] += 1
            elif S[i][j] == "W":
                cnt[j][1] += 1
            else:
                cnt[j][2] += 1
    
    ans = 0
    c1 = cnt[0][2]
    c2 = cnt[1][2]
    for b1 in range(cnt[0][2] + 1):
        w1 = cnt[0][2] - b1
        b = b1 + cnt[0][0]
        w = w1 + cnt[0][1]
        b2 = b - cnt[1][0]
        w2 = w - cnt[1][1]
        if b2 < 0 or w2 < 0:
            continue
        ans += nCk(c1, b1) * nCk(c2, b2)
        ans %= MOD
    
    if cnt[0][0] == 0 and cnt[1][0] == 0:
        ans += 1
    if cnt[0][1] == 0 and cnt[1][1] == 0:
        ans += 1
    
    print((ans - minus) % MOD)
    
    
    
for _ in range(1):
    main()