t = int(input())
for _ in range(t):
    a = sorted(map(int, input().split()))
    ans = 0
    for i in range(3):
        if a[i] > 0:
            a[i] -= 1
            ans += 1
    a = a[::-1]
    for i in range(3):
        for j in range(i):
            if a[i] > 0 and a[j] > 0:
                a[i] -= 1
                a[j] -= 1
                ans += 1
    if min(a) > 0:
        ans += 1
    print(ans)