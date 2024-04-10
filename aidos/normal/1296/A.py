t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    ok = False
    for i in range(n):
        if a[i] % 2 != a[0] % 2:
            ok = True
    if ok or sum(a) % 2 == 1:
        print("YES")
    else:
        print("NO")