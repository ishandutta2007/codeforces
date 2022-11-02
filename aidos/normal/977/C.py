n, k = map(int, input().split())
a = sorted(map(int, input().split()))
if k == 0:
    if a[0] == 1:
        print(-1)
    else:
        print(1)
elif k == n:
    print(10**9)
elif a[k] == a[k-1]:
    print(-1)
else:
    print(a[k-1])