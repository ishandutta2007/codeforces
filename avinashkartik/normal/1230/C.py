n,k = map(int,input().split())
s = [[0 for i in range(8)] for j in range(8)]
for i in range(k):
	u,v = map(int,input().split())
	s[u][v] = 1
	s[v][u] = 1
if(n <= 6 or k == 0):
	print(k)
else:
	a = []
	for i in range(1,8):
		for j in range(1,8):
			if(i == j):
				continue
			ct = 0
			for k in range(1,8):
				if s[i][k] == 1 and s[j][k] == 1:
					ct += 1
			#print(j,i,ct)
			a.append([ct,i,j])
	a.sort()
	ind1 = a[0][1]
	ind2 = a[0][2]
	sum = sum1 = 0
	#print(a[0][0],ind1,ind2)
	#print(s[ind1],s[ind2])
	for i in range(1,8):
		if(s[ind1][i] == 1 and s[ind2][i] == 1):
			sum1 += 1
		elif(s[ind1][i] != s[ind2][i]):
			sum1 += 1

	if(s[ind1][ind2] == 1 and s[ind2][ind1] == 1):
		sum1 -= 1
	for i in range(1,8):
		#print(s[i])
		if i == ind1 or i == ind2:
			continue
		for j in range(1,8):
			if j == ind1 or j == ind2:
				continue
			sum += s[i][j]
		#print(sum)
	print(sum1+(sum//2))