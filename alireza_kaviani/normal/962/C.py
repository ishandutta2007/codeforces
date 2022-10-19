n = input()
ans = 1000;
ln = len(n)

for i in range(1 , 2 ** ln):
	bn = str(bin(i))[2:]
	s = ''
	for j in range(len(bn)):
		if(bn[j] == '1'):
			s += n[j + (len(n) - len(bn))]
	
	if(s[0] != '0'):
		s = int(s)
		sqr = int(s ** .5)
		if(sqr * sqr == s and i != 0):
			ans = min(ans , len(n) - bn.count('1'))

if(ans == 1000):
	print(-1)
else:
	print(ans)