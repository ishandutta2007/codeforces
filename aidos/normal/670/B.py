n, k = map(int, input().split())
a = list(map(int, input().split()))
for i in range(n):
    if k >= i + 2:
        k -= i + 1
    else:
        print(a[k-1])
        break