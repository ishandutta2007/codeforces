k = int(input())
s = input()
n = len(s)
if(s.count('1') < k):
	print(0)
	exit(0)
if(k == 0):
	ans = 0
	ct = 0
	for j in range(n):
		if(s[j] == '0'):
			ct += 1
		if(s[j] == '1' or j == n-1):
			ans += ct*(ct+1)//2
			ct = 0
else:
	i,j,ct = 0,0,0
	for j in range(n):
		if(s[j] == '1'):
			ct += 1
		if(ct == k):
			break
	i = s.find('1')
	ans = 0
	b = i
	while(j < n):
		j += 1
		a = 0
		while(j < n and s[j] == '0'):
			a += 1
			j += 1
		ans += (b+1)*(a+1)

		i += 1
		b = 0
		while(i < n and s[i] == '0'):
			b += 1
			i += 1
print(ans)