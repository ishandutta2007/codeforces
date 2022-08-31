l = list(input())
ct = 0
n = len(l)
for i in range(n-1,-1,-1):
	if(l[i] == '0'):
		ct += 1
	else:
		if(ct != 0):
			ct -= 1
		else:
			l[i] = '0'
print(''.join(l))