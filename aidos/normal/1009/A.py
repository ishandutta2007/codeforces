n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
i, j = 0, 0
while i < n and j < m:
    if a[i] <= b[j]:
        j += 1
    i += 1
print(j)