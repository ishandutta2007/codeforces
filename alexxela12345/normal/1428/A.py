t = int(input())
for i in range(t):
    x1, y1, x2, y2 = list(map(int, input().split()))
    if x1 == x2:
        print(abs(y1 - y2))
    elif y1 == y2:
        print(abs(x1 - x2))
    else:
        print(abs(x1 - x2) + abs(y1 - y2) + 2)