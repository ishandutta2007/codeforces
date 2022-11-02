n, m = map(int, input().split())
a = [1]*m
for i in range(n):
    l, r = map(int, input().split())
    for j in range(l-1, r):
        a[j] = 0

print(sum(a))

for i in range(m):
    if a[i]:
        print(i+1, sep = ' ')