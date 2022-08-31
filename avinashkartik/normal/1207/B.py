n ,m= map(int,input().split())
a = [list(map(int,input().split())) for j in range(n)]
b = [[0 for i in range(m)]for j in range(n)]
#print(a)
c = 0
l = []
s = 0
for i in a:
	s += sum(i)
if(s == 0):
	print(0)
else:
	for i in range(n-1):
		for j in range(m-1):
			if(a[i][j] == a[i+1][j+1] == a[i+1][j] == a[i][j+1] == 1):
				l.append([i+1,j+1])
				b[i][j] = b[i+1][j+1] = b[i+1][j] = b[i][j+1] = 1
	if(len(l) and b==a):
		print(len(l))
		for i in l:
			print(i[0],i[1])
	else:
		print(-1)