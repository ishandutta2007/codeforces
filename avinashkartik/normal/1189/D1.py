n = int(input())
l = [[] for i in range(n+1)]
for y in range(n-1):
	u,v = map(int,input().split())
	l[u].append(v)
	l[v].append(u)
for i in range(1,n+1):
	if len(l[i]) == 2:
		print("NO")
		break
else:
	print("YES")