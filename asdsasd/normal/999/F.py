import sys
input = sys.stdin.readline

def main():
    n, K = map(int, input().split())
    C = list(map(int, input().split()))
    F = list(map(int, input().split()))
    H = list(map(int, input().split()))
    cnt = {}
    for f in F:
        cnt[f] = cnt.get(f, 0) + 1
    cnt2 = {}
    for c in C:
        cnt2[c] = cnt2.get(c, 0) + 1
    
    ans = 0
    for k, v in cnt.items():
        if k not in cnt2:
            continue
        x = cnt2[k]
        dp = [[0] * (x + 1) for _ in range(v + 1)]
        for i in range(1, v + 1):
            for j in range(K, 0, -1):
                p = H[j - 1]
                for l in range(x, j - 1, -1):
                    dp[i][l] = max(dp[i][l], dp[i - 1][l - j] + p)
        ans += dp[-1][-1]
    print(ans)
            
        
        
    
    
for _ in range(1):
    main()