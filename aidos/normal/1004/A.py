n, d = map(int, input().split())
a = list(map(int, input().split()))
s = set()
s.add(a[0] - d)
s.add(a[-1] + d)
for i in range(1, n):
    if a[i-1] + d + d <= a[i]:
        s.add(a[i-1] + d)
        s.add(a[i] - d)
print(len(s))