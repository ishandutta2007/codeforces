n, k = map(int, input().split())
a = list(map(int, input().split()))
a = [0] + a
b = []
s = 0
for i in range(n+1):
    s += a[i]
    if i >= k:
        s-= a[i-k]
        b.append(s)

print(sum(b)/(n-k+1))