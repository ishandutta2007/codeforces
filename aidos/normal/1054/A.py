x, y, z, t1, t2, t3 = map(int, input().split())
a = abs(x-z) * t2 + abs(y-x) * t2 + 3 * t3
b = abs(y-x) * t1
if a <= b:
    print('YES')
else:
    print('NO')