n = int(input())
a = []
for i in range(n):
	a.append(list(map(int,input().split()))+[i+1])
a.sort()
x = a[0]
y = a[1]
if(x[1] == y[1]):
	m = 0
else: m = (x[0]-y[0])/(x[1]-y[1])
for i in range(2,n):
	if (a[i][0] == x[0] and a[i][0] == y[0]) or (a[i][1] == x[1] and a[i][1] == y[1]) or ((a[i][0]-x[0]) == (a[i][1]-x[1])*m) or ((a[i][0]-x[0]) == 0 and m == 0):
		continue
	z = a[i]
	break
print(x[2],y[2],z[2])