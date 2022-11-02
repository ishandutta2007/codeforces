n = int(input())
a = map(int, input().split())
b = []
for x in a:
    y = x
    cnt = 0
    while y % 3 == 0:
        y//=3
        cnt += 1
    b.append([-cnt, x])
b = sorted(b)
for x in b:
    print(x[1], end = ' ')