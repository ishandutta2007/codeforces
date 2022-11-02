n = int(input())
a = list(map(int, input().split()))
b = [0] * n
for i in range(n-1, -1, -1):
    if i == n-1:
        b[i] = a[i]
    else:
        b[i] = a[i] + a[i+1]
for i in range(n):
    print(b[i], end = ' ')