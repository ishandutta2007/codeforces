t = int(input())
for y in range(t):
	n = int(input())
	a = input()
	i = a.count('A')
	if(i == 0): print(0)
	else:
		ct = 0
		i = a.index('A')
		i += 1
		while(i < n):
			st = i
			while(i < n and a[i] != 'A'):
				i += 1
			ct = max(ct,i-st)
			i += 1
		print(ct)