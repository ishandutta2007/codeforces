n, b, d = map(int, input().split())
s = 0
a = list(map(int, input().split()))
cnt = 0
for i in range(n):
    if a[i] > b:
        continue
    s += a[i]
    if s > d:
        s = 0
        cnt += 1
print(cnt)