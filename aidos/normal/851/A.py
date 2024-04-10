n, k, t = map(int, input().split())
if t <= k:
    print(t)
elif t > n:
    print(k-(t-n))
else:
    print(k)