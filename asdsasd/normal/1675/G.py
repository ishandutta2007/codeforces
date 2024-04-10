import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    inf = 1 << 30
    cum = [0]
    for a in A:
        cum.append(cum[-1] + a)

    def f(i, j, k):
        return (i * (m + 1) + j) * (m + 1) + k

    dp = [inf] * ((n + 1) * (m + 1) * (m + 1))
    dp[f(0, 0, m)] = 0
    
    for i in range(n):
        for j in range(m + 1):
            min_ = inf
            for k in range(m, -1, -1):
                min_ = min(min_, dp[f(i, j, k)])
                if j + k <= m:
                    dp[f(i + 1, j + k, k)] = min(dp[f(i + 1, j +  k, k)], min_ + abs(cum[i + 1] - (j + k)))

    ans = inf
    for k in range(m + 1):
        ans = min(ans, dp[f(n, m, k)])
    print(ans)

for _ in range(1):
    main()