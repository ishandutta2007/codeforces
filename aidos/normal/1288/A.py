t = int(input())
for _ in range(t):
    n, d = map(int, input().split())
    x = d
    for i in range(1, 40000):
        x = min(x, i + (d+i)//(i+1))
    if x <= n:
        print('YES')
    else:
        print('NO')