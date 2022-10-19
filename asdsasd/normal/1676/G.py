import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    S = input().strip()
    edges = [[] for _ in range(n)]
    for i, a in enumerate(A, 1):
        edges[a - 1].append(i)
    stack = [0]
    route = [0]
    while stack:
        pos = stack.pop()
        for npos in edges[pos]:
            stack.append(npos)
            route.append(npos)
    dp = [0] * n
    ans = 0
    for pos in route[::-1]:
        if S[pos] == "W":
            dp[pos] = 1
        else:
            dp[pos] = -1
        for npos in edges[pos]:
            dp[pos] += dp[npos]
        if dp[pos] == 0:
            ans += 1
    print(ans)



for _ in range(int(input())):
    main()