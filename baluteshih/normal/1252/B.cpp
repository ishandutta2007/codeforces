q = int(input())
for tc in range(q):
    data = input().split(' ')
    a, b, n, S = int(data[0]), int(data[1]), int(data[2]), int(data[3])
    x = S//n
    if a < x:
        x = a
    if x * n + b < S:
        print('NO')
    else:
        print('YES')