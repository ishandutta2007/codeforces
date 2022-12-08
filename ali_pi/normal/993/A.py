rd = lambda: list(map(int,raw_input().split()))
z = []
for i in 'ii':
    a = rd()
    z += [a[::2], a[1::2]]
for x in z:
    x.sort()
u, v, x, y = z
for i in range(u[0], u[3] + 1):
    for j in range(v[0], v[3] + 1):
        if x[0] + y[1] <= i + j <= x[3] + y[1] and y[0] - x[1] <= j - i <= y[3] - x[1]:
            print('YES')
            exit()
print('NO')