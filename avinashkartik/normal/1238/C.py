from math import *
t = int(input())
for i in range(t):
	n,r = map(int,input().split())
	l = list(map(int,input().split()))
	l.append(0)
	l = l[::-1]
	if(n <= 2):
		print(0)
	else:
		ct = 0
		i = r
		while(i > 1):
			#print(l[i],end = " ")
			if(l[i] - l[i-1] == 1 and l[i] - l[i-2] != 2):
				ct += 1
				l[i-1] -= 1
				i -= 1
			elif(l[i] - l[i-1] == 1):
				i -= 2
			else:
				l[i] = l[i-1]+1
		print(ct)