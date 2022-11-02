n, a, x, b, y = map(int, input().split())
a -= 1
x -= 1
b -= 1
y -= 1
while a != b and a != x and b != y:
    a = (a+1) % n
    b = (b-1) % n
if a == b:
    print('YES')
else:
    print('NO')