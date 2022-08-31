n,L,a = map(int,input().split())
l = []
for i in range(n):
	l.append(list(map(int,input().split())))
l.sort()
l.append([L,0])
t = 0
ans = 0
for i in range(n+1):
	ans += (l[i][0]-t)//a
	t = l[i][0]+l[i][1]
print(ans)