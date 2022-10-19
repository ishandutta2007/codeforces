n, m, k = map(int, input().split())
a = [1000000]*m
for i in range(n):
    r, c = map(int, input().split())
    a[r - 1] = min(a[r - 1], c)
print(min(sum(a), k))