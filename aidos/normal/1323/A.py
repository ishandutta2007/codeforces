t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    if a[0] % 2 == 0:
        print(1)
        print(1)
        continue
    if n == 1:
        print(-1)
        continue
    if sum(a) % 2 == 1:
        print(n-1)
        print(' '.join([str(i+1) for i in range(1, n)]))
    else:
        print(n)
        print(' '.join([str(i + 1) for i in range(n)]))