n, k = map(int, input().split())
matr = [[0] * n for i in range(n)]
p = 1
for i in range(n):
    for j in range(k - 1):
        matr[i][j] = p
        p += 1
for i in range(n):
    for j in range(k - 1, n):
        matr[i][j] = p
        p += 1
st = 0
for i in range(n):
    st += matr[i][k - 1]
print(st)
for i in range(n):
    for j in range(n):
        print(matr[i][j], end = ' ')
    print()