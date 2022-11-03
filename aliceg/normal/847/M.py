import sys


n = int(input())
a = list(map(int, input().split()))
d = a[1] - a[0]
flag = False
for i in range(1, n):
    if a[i] - a[i - 1] != d:
        flag = True
        break

if not flag:
    print(a[n - 1] + d)
else:
    print(a[n - 1])