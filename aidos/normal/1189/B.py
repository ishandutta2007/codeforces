n = int(input())
a = sorted(map(int, input().split()))
if a[n-1] >= a[n-2] + a[n-3]:
    print('NO')
else:
    b = a[:n-2] + [a[n-1], a[n-2]]
    print('YES')
    print(' '.join(map(str, b)))