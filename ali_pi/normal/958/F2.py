n, m = map(int,raw_input().split())
c = list(map(int,raw_input().split()))
k = list(map(int,raw_input().split()))
p = [0] * m
c = [i -1 for i in c]
s = sum(k)
cnt = k.count(0)
l = 0
r = 0
while r < n and cnt < m:
    p[c[r]] += 1
    if p[c[r]] == k[c[r]]:
        cnt += 1
    r += 1
if cnt != m:
    print(-1)
    exit(0)
ans = r-l
while l < n:
    p[c[l]] -= 1
    while r < n and p[c[l]] < k[c[l]]:
        p[c[r]] += 1
        r += 1
    if p[c[l]] >= k[c[l]]:
        ans = min(ans, r-l-1)
    elif r == n:
        break
    l += 1
print(ans-s)