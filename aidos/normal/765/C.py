k, a, b = map(int, input().split())
if a > b:
    a, b = b, a
if a < k:
    if b % k != 0:
        print(-1)
    else:
        print(b//k)
else:
    print(a//k+b//k)