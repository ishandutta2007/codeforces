x, n = list(map(int, input().split()))
a = [False for i in range(x)]

for i in range(n):
    d = int(input()) % x
    if a[d]:
        print(i + 1)
        break
    a[d] = True
else:
    print(-1)