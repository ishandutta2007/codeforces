n = int(input())
a = list(map(int, input().split()))
l = [-1] * n
r = [-1] * n

for i in range(2*n):
    a[i] -= 1
    if l[a[i]] == -1:
        l[a[i]] = i
    r[a[i]] = i

x = l[0]
y = r[0]
for i in range(1, n):
    if x+abs(l[i-1]-l[i])+ y + abs(r[i-1] - r[i]) < x+abs(l[i-1]-r[i])+y + abs(r[i-1] - l[i]):
        x, y = x+abs(l[i-1]-l[i]), y + abs(r[i-1] - r[i])
    else:
        x, y = x+abs(l[i-1]-r[i]), y + abs(r[i-1] - l[i])
print(x+y)