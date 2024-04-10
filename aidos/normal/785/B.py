n = int(input())
al = []
ar = []
bl = []
br = []
ans = 0
for i in range(n):
    x, y = map(int, input().split())
    al.append(x)
    ar.append(y)
m = int(input())
for i in range(m):
    x, y = map(int, input().split())
    bl.append(x)
    br.append(y)
ans = max(0, max(max(al) - min(br), max(bl) - min(ar)))
print(ans)