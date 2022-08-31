n = int(input())
a = list(map(int,input().split()))
m = abs(2*a[0]-360)
for i in range(n):
	for j in range(i+1,n+1):
		s = 0
		if(i == 0 and j == n): continue
		for k in range(i,j):
			s += a[k]
		m = min(m,abs(2*s-360))
print(m)