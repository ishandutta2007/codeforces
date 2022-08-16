t = int(input())
for y in range(t):
	n = int(input())
	s = input()
	pre = [0 for i in range(n+1)]
	for i in range(n):
		if(s[i] == 'L'): pre[i+1] = pre[i]+1
		elif(s[i] == 'R'): pre[i+1] = pre[i]-1
		elif(s[i] == 'U'): pre[i+1] = pre[i]+int(1e6)
		else: pre[i+1] = pre[i]-int(1e6)
	#print(pre)
	d = dict()
	ans = -1
	l = r = -1
	for i in range(n+1):
		if pre[i] not in d:
			d[pre[i]] = i
		else:
			if ans == -1 or i - d[pre[i]] < ans:
				ans  = i - d[pre[i]]
				l = d[pre[i]]+1
				r = i
			d[pre[i]] = i
	if(ans == -1): print(ans)
	else: print(l,r)