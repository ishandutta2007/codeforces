t = int(input())
for y in range(t):
	s = input()
	ct = 0
	ans = 0
	for i in s:
		if(i == 'L'):
			ct += 1
		else:
			ans = max(ans,ct)
			ct = 0
	print(max(ans,ct)+1)