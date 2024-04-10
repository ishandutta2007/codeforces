n = int(input())
alst = list(map(int, input().split()))

if n == 1:
    print(1, 1)
    print(alst[0] * -1)
    print(1, 1)
    print(alst[0] * -1)
    print(1, 1)
    print(alst[0])
else:
    print(1, n)
    row = []
    for i, a in enumerate(alst):
        tmp = (a - 1) % (n - 1) + 1
        plus = (n - 1 - tmp) * n
        row.append(plus)
        alst[i] += plus
    print(*row)
    print(1, 1)
    print(-1 * alst[0])
    print(2, n)
    row = []
    for a in alst[1:]:
        row.append(a * -1)
    print(*row)