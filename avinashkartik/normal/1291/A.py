t = int(input())
for y in range(t):
	n = int(input())
	s = input()
	ss = 0
	f = l = -1
	for i in range(n):
		if(int(s[i])&1 and f == -1):
			f = i
		if(int(s[i])&1):
			l = i
	if(f == l): print(-1)
	else: print(s[f]+s[l])