n, m = map(int, input().split())
a = [0] * n
for i in range(n):
    a[i] = list(map(int, input().split()))
a.sort()
r = 0
while r < m:
    i = 0
    r1 = 0
    while i < n and a[i][0] <= r:
        r1 = max(r1, a[i][1])
        i += 1
    if r1 <= r:
        print('NO')
        exit()
    r = r1
print('YES')