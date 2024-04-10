n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
s = sum(a)
ans = s
c = sorted([b[i]-a[i] for i in range(n)])
k = n-k
for i in range(k):
    s += c[i]
    if ans > s:
        ans = s
print(ans)