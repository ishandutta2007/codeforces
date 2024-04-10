t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    i = 0
    while i < n and a[i] == b[i]:
        i += 1
    if i == n:
        print('YES')
        continue
    k = b[i] - a[i]
    for j in range(i, n):
        if b[j] - a[j] == k:
            a[j] += k
        else:
            break
    if k <= 0 or a != b:
        print('NO')
    else:
        print('YES')