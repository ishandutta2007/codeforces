m, d = map(int, input().split())
m -= 1
d -= 1
a = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
cnt = 1
for i in range(a[m]):
    if d == 0 and i > 0:
        cnt += 1
    d = (d+1) % 7
print(cnt)