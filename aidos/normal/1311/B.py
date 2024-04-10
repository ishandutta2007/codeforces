t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    p = list(map(int, input().split()))
    for it in range(n):
        for j in range(1, n):
            if j in p and a[j-1] > a[j]:
                a[j-1], a[j] = a[j], a[j-1]
    b = sorted(a)
    if a == b:
        print('YES')
    else:
        print('NO')