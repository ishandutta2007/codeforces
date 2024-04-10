n = int(input())
a = list(map(int, input().split()))
a = [0] + a
for j in range(1, n):
    a[j] += a[j-1]
h = min(a)
for j in range(n):
    a[j] -= h - 1
t = set(a)
if len(t) == n and max(a) == n and min(a)==1:
    for x in a:
        print(x, end = ' ')
else:
    print(-1)