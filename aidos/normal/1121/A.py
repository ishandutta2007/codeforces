n, m, k = map(int, input().split())
p = list(map(int, input().split()))
s = list(map(int, input().split()))
c = list(map(int, input().split()))
a = [0] * m
for i in range(n):
    a[s[i] - 1] = max(a[s[i] - 1], p[i])
cnt = 0

for i in c:
    if a[s[i-1] - 1] != p[i-1]:
        cnt += 1
print(cnt)