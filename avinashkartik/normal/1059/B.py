n,m = map(int,input().split())
a = []
b = [['.' for i in range(m)] for j in range(n)]
for i in range(n):
	a.append(list(input()))
f = 0
for i in range(n-2):
	for j in range(m-2):
		if(a[i][j] == '#' and a[i+1][j] == '#' and a[i+2][j] == '#' and a[i][j+1] == '#' and a[i+2][j+1] == '#' and a[i][j+2] == '#' and a[i+1][j+2] == '#' and a[i+2][j+2] == '#'):
			b[i][j] = '#'
			b[i+1][j] = '#'
			b[i+2][j] = '#'
			b[i][j+1] = '#'
			b[i+2][j+1] = '#'
			b[i][j+2] = '#'
			b[i+1][j+2] = '#'
			b[i+2][j+2] = '#'
if(a == b):
	print("YES")
else:
	print("NO")