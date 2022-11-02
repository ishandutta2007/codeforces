n = int(input())
a = [0] * (n+1)
b = [0] * (n+1)
for i in range(n*n):
    x, y = map(int, input().split())
    if a[x] + b[y] == 0:
        a[x] = 1
        b[y] = 1
        print(i+1, end = ' ')