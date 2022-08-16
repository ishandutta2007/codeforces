s = input()
n = len(s)
c = dict()
ans = 1e18
c['2'],c['5'],c['7'],c['0'] = 0,0,0,0
for i in s:
	if(i not in c): c[i] = 0
	c[i] += 1
if(c['0'] >= 2):
	res = -1
	for i in range(n-1,-1,-1):
		if(s[i] == '0'):
			if(res == -1): res = n-1-i
			else:
				res += n-2-i
				break
	ans = min(ans,res)
if(c['0'] and c['5']):
	res = 0
	f = 0
	for i in range(n-1,-1,-1):
		if(s[i] == '0'):
			res += n-1-i
			break
		if(s[i] == '5'):
			f = 1
	for i in range(n-1,-1,-1):
		if(s[i] == '5'):
			res += max(0,n-2-i+f)
			break
	ans = min(ans,res)
if(c['2'] and c['5']):
	res = 0
	f = 0
	flag = 0
	for i in range(n-1,-1,-1):
		if(s[i] == '5'):
			res += n-1-i
			break
		if(s[i] == '2'):
			f = 1
	if(i == 0 and s[1] == '0'):
		for i in range(1,n):
			if(s[i] != '0'):
				break
		flag = i-1
	for i in range(n-1,-1,-1):
		if(s[i] == '2'):
			res += max(0,n-2-i+f)
			break
	ans = min(ans,res+flag)
if(c['7'] and c['5']):
	res = 0
	f = 0
	flag = 0
	for i in range(n-1,-1,-1):
		if(s[i] == '5'):
			res += n-1-i
			break
		if(s[i] == '7'):
			f = 1
	if(i == 0 and s[1] == '0'):
		for i in range(1,n):
			if(s[i] != '0'):
				break
		flag = i-1
	for i in range(n-1,-1,-1):
		if(s[i] == '7'):
			res += max(0,n-2-i+f)
			break
	ans = min(ans,res+flag)
if(ans == 1e18):
	ans = -1
print(ans)