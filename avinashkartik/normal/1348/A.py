t = int(input())
for y in range(t):
	n = int(input())
	res = pow(2,n)
	for i in range(n-1,0,-1):
		if(i >= n//2): res -= pow(2,i)
		else: res += pow(2,i)
	print(int(res))