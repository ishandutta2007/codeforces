n = int(input())
a = list(map(int, input().split()))

for i in range(n):
    mi = 10**10
    if i > 0:
        mi = min(mi, a[i] - a[i-1])
    if i + 1 < n:
        mi = min(mi, a[i+1] - a[i])
    print(mi, max(a[n-1]-a[i], a[i] - a[0]))