n,m = map(int,input().split())
a = [[0 for i in range(m)] for i in range(n)]
c = [[0 for i in range(m)] for i in range(n)]
b = []
for i in range(n):
	b.append(list(map(int,input().split())))
for i in range(n):
	for j in range(m):
		if(b[i][j] == 1):
			f = 1
			for k in range(n):
				f &= b[k][j]
			for k in range(m):
				f &= b[i][k]
			a[i][j] = f
for i in range(n):
	for j in range(m):
		if(a[i][j] == 1):
			for k in range(n):
				c[k][j] = 1
			for k in range(m):
				c[i][k] = 1
if(b == c):
	print("YES")
	for i in range(n):
		print(*a[i])
else:
	print("NO")