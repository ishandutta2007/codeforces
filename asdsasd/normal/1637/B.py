import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    ans = 0
    for i in range(n):
        mex = 0
        se = set()
        dp = [0] * (n + 1)
        for j in range(i, n):
            se = set()
            mex = 0
            for k in range(j, i - 1, -1):
                se.add(A[k])
                while mex in se:
                    mex += 1
                dp[j + 1] = max(dp[j + 1], dp[k] + mex + 1)
            ans += dp[j + 1]
        
        
            
    print(ans)
            
    
for _ in range(int(input())):
    main()