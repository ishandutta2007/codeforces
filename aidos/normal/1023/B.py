n, k = map(int, input().split())
if n >= k-1:
    print((k-1)//2)
else:
    print(max(n - k//2, 0))