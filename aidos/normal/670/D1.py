n, k = map(int, input().split())
b = list(map(int, input().split()))
a = list(map(int, input().split()))
c = []
x = 0
for i in range(n):
    c.append([a[i]//b[i], a[i], b[i]])
c.append([10**12, 0, 10**10])
c = sorted(c)
ans = c[0][0]
suma = 0
sumb = 0
i = 0
n += 1
while i < n:
    j = i
    cura = 0
    curb = 0
    while i < n and c[j][0] == c[i][0]:
        cura += c[i][1]
        curb += c[i][2]
        i += 1
    if sumb * c[j][0] - suma <= k:
        ans = max(ans, c[j][0])
    else:
        ans = max(ans, min((suma + k)//sumb, c[j][0]-1))
        break
    suma += cura
    sumb += curb
print(ans)