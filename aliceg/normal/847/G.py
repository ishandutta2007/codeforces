import sys

n = int(input())
res = [0] * 7
for k in range(n):
    a = [int(i) for i in input()]
    for j in range(7):
        res[j] += a[j]

print(max(res))