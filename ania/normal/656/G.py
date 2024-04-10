n, m, t = map(int, input().split())
s=[0]*n
R=i=j=0
#kitten
while i<n:
	s[i]=input()
	i+=1
while j<m:
	C=0
	for i in range (0,n):
		if s[i][j] == 'Y':
			C+=1
	if C >= t:
		R+=1
	j+=1
print(R)