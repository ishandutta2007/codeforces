a = sorted(map(int, input().split()))
if a[0] + a[3] == a[1] + a[2] or sum(a) - a[3] == a[3]:
    print("YES")
else:
    print("NO")