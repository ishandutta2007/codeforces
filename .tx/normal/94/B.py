a = [[False] * 5 for i in range(5)]

m = int(input())

for i in range(m):
    x, y = map(int, input().split(' '))
    x -= 1
    y -= 1
    a[x][y] = a[y][x] = True

for i in range(5):
    for j in range(5):
        if i == j:
            continue
        for k in range(5):
            if i == k or j == k:
                continue
            if a[i][j] == a[i][k] and a[i][j] == a[j][k]:
                print("WIN")
                exit(0)

print("FAIL")