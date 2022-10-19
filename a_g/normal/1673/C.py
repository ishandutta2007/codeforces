M=10**9+7
m=40001
r=range
v=[1]+[0]*m
for i in r(1,m):
	if str(i)==str(i)[::-1]:
		for j in r(i,m):v[j]=v[j]%M+v[j-i]
for n in[*open(0)][1:]:print(v[int(n)]%M)