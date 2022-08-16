n = int(input())
s = input()
if(n %2 == 1):
	print(1)
	print(s)
else:
	c0 = s.count('0')
	c1 = s.count('1')
	if(c0 == c1):
		print(2)
		print(s[0],s[1:])
	else:
		print(1)
		print(s)