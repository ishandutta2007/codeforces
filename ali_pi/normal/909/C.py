mod = 10**9+7
n = input()
x = [1]
for i in range(n):
	s = raw_input()
	if s=='f':
		x.insert(0,0)
	else:
		for i in range(len(x)-2,-1,-1):
			x[i] = (x[i]+x[i+1])%mod
print x[0]