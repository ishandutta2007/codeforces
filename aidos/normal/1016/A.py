n, m = map(int, input().split())
sum = 0
a = list(map(int, input().split()))
ans = 0
for i in range(n):
    sum += a[i]
    print(sum//m, end = ' ')
    sum %= m