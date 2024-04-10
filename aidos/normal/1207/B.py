n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]
b = [[0]*m for _ in range(n)]
ans = []
for i in range(n-1):
    for j in range(m-1):
        if a[i][j] == 1 and a[i+1][j] == 1 and a[i][j+1] and a[i+1][j+1]:
            b[i][j], b[i+1][j], b[i][j+1], b[i+1][j+1] = 1,1,1,1
            ans.append([i+1, j+1])

if a == b:
    print(len(ans))
    for x in ans:
        print(x[0], x[1])
else:
    print(-1)