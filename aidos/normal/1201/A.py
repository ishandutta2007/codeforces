n, m = map(int, input().split())
s = [input() for _ in range(n)]
cost = list(map(int, input().split()))
ans = 0
for i in range(m):
    mx = 0
    for c in "ABCDEF":
        cnt = 0
        for j in range(n):
            if s[j][i] == c:
                cnt += 1
        mx = max(mx, cnt)
    ans += mx * cost[i]
print(ans)