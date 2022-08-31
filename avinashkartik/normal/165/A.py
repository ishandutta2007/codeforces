n = int(input())
a = []
for i in range(n):
	a.append(list(map(int,input().split())))
ct = 0
for i in range(n):
	l,r,u,d = 0,0,0,0
	for j in range(n):
		if(a[j][0] < a[i][0] and a[j][1] == a[i][1]):
			l += 1
		if(a[j][0] > a[i][0] and a[j][1] == a[i][1]):
			r += 1
		if(a[j][1] < a[i][1] and a[j][0] == a[i][0]):
			u += 1
		if(a[j][1] > a[i][1] and a[j][0] == a[i][0]):
			d += 1
	if(l and r and u and d):
		ct += 1
print(ct)