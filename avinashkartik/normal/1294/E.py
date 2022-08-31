m,n = map(int,input().split())
a = []
ans = 0
for y in range(m):
	a.append(list(map(int,input().split())))
for i in range(n):
	ch = (i+1)%n
	ar = [0 for y in range(m)]
	for j in range(m):
		if a[j][i]%n == ch and a[j][i] <= m*n:
			ind = (a[j][i]-1)//n
			if j >= ind:
				ar[j-ind] += 1
			else:
				ar[m+j-ind] += 1
	maxx = 0
	indmax = -1
	for j in range(m):
		if maxx < ar[j]-j: 
			maxx = ar[j]-j
			indmax = j
	if indmax == -1: ans += m
	else: ans += indmax + m - ar[indmax]
	#print(ar,ans)
print(ans)