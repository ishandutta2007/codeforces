n, k = map(int, input().split())
a = sorted(map(int, input().split()))
x = 0
b = []
for i in range(n):
    if x < a[i]:
        b.append(a[i]-x)
        x = a[i]
while len(b) < k:
    b.append(0)
for i in range(k):
    print(b[i])