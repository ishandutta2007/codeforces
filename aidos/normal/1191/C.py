n, m, k = map(int, input().split())
p = list(map(int, input().split()))
c = 0
d = 0
i = 0
while i < m:
    cur = (p[i] - d - 1)//k
    x = d
    while i < m and cur * k + k >= p[i] - x:
        i += 1
        d += 1
    c+=1
print(c)