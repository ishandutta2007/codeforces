n,m = map(int, raw_input().split())
p = 100043
k = 1
print p,p
print 1,2, p-n+2
j = 2
while k<n-1:
	k+=1
	print j,j+1,1
	j+=1
i = 1
j = 3
while k<m:
	if(j>n):
		j = i+2
		i+=1
	if(j==i+1):
		pass
	else:
		print i, j, 99999999
		k+=1
	j+=1