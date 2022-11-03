t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(map(int, input().split()))
    if n < 3 or a[n-2] < 2:
        print(0)
    else:
        print(min(a[n-2]-1, n-2))