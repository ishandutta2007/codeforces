t = int(input())
for i in range(t):
    x, y = map(int, input().split())
    if x >= y:
        print('YES')
    elif x == 1:
        print('NO')
    elif y <= 3:
        print('YES')
    elif x <= 3:
        print('NO')
    else:
        print('YES')