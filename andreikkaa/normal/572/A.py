na, nb = map(int, input().split())
k, m = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

if a[k - 1] < b[-m]:
    print("YES")
else:
    print("NO")