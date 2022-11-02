n = int(input())
a = [0]
for i in range(n):
    b = []
    x = int(input())
    for j in a:
        b.append((j+x) % 360)
        b.append((j-x) % 360)
    a = list(set(b))
if 0 in a:
    print('YES')
else:
    print('NO')