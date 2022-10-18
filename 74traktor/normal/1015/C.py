n,m = map(int,input().split())
s = 0
a = []
for i in range(n):
	x,y = map(int,input().split())
	s += x
	a.append(x - y)
a.sort(reverse = True)
i = 0
while i < n and s > m:
	s -= a[i]
	i +=1
if s <= m:
	print(i)
else:
	print(-1)