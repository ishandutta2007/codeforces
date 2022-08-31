t = int(input())
for y in range(t):	
	n = int(input())
	if(n == 1):
		print(-1)
		continue
	s = []
	for i in range(n-1):
		s.append('2')
	s.append('3')
	if((n-1)%3 == 0): s[0] = '3'
	print("".join(s))