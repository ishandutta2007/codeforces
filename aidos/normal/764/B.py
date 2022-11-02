n = int(input())
a = list(map(int, input().split()))
cnt = 0
b = [0] * n
for i in range(n//2):
    cnt += 1
    b[i] = cnt % 2
    b[n-i-1] = cnt % 2
for i in range(n):
    if b[i]:
        print(a[n-i-1], end = ' ')
    else:
        print(a[i], end = ' ')