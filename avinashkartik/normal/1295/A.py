t = int(input())
for y in range(t):
	n = int(input())
	s = ""
	if(n%2 == 1):
		s += '7'
		n -= 3
	s += (n//2)*'1'
	print(int(s))