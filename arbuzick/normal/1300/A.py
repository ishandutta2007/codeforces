t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    s = 0
    k = 0
    for j in range(n):
        if a[j] == 0:
            a[j] += 1
            k += 1
        s += a[j]
    if s == 0:
        k += 1
    print(k)