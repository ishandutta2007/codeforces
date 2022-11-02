n, m = map(int, input().split())
if m == n:
    print(0)
elif m<=1:
    print(1)
else:
    print(min(m, n-m))