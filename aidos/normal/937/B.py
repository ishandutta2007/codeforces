p, y = map(int, input().split())
while y > p:
    if y % 2 == 0:
        y -= 1
        continue
    good = 1
    i = 3
    while i * i <= y and i <= p:
        if y % i == 0:
            good = 0
            break
        i += 2
    if good:
        break
    y -= 1
if y == p:
    print(-1)
else:
    print(y)