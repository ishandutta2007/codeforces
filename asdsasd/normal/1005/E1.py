import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    dp = [{0:1}, {}]
    t = 0
    tot = 0
    for a in A:
        if a == k:
            t = 1
        elif a > k:
            tot += 1
        else:
            tot -= 1
        dp[t][tot] = dp[t].get(tot, 0) + 1
    
    ans = 0
    for k, v in dp[0].items():
        tmp = dp[1].get(k, 0) + dp[1].get(k + 1, 0)
        ans += v * tmp
    print(ans)
    
for _ in range(1):
    main()