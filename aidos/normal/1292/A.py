n, q = map(int, input().split())
u = [[0] * (n + 3), [0] * (n+3)]
cnt = 0
for _ in range(q):
    r, c = map(int, input().split())
    r -= 1
    for j in range(-1, 2):
        if u[1-r][c+j]:
            cnt -= u[r][c]
    u[r][c] = 1-u[r][c]
    for j in range(-1, 2):
        if u[1 - r][c + j]:
            cnt += u[r][c]
    if cnt > 0:
        print('No')
    else:
        print('Yes')