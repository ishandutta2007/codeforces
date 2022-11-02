n, d = map(int, input().split())
m = int(input())
for i in range(m):
    x, y = map(int, input().split())
    if x + y < d or abs(x-y) > d or x+y > 2*n-d:
        print('NO')
    else:
        print('YES')