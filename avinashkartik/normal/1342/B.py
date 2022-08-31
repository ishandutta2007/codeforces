test = int(input())
for yy in range(test):
	s = input()
	if(s.count('0') == 0 or s.count('1') == 0):
		print(s)
	else:
		for i in range(2*len(s)):
			print(i%2,end = "")
		print()