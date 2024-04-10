n = int(input())
a = map(int, input().split())
d = dict()
for i in a:
    d[i] = d.get(i, 0) + 1
m = int(input())
b = list(map(int, input().split()))
c = list(map(int, input().split()))

ans = [-1, -1]
ind = -1

for i in range(m):
    x = [d.get(b[i], 0), d.get(c[i], 0)]
    if ans < x:
        ans = x
        ind = i
print(ind+1)