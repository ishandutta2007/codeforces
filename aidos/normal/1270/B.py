t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    good = True
    for i in range(1, n):
        if abs(a[i] - a[i-1]) >= 2:
            good = False
            print('YES')
            print(i, i + 1)
            break
    if good:
        print('NO')