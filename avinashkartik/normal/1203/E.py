from math import *

n = int(input())
l = list(map(int,input().split()))
d = dict()
l1  = l[:]
l.sort(reverse = True)
for i in l:
	if i in d:
		d[i] += 1
	else:
		d[i] = 1
c = [0 for i in range(n)]

for i in range(n):
	#print(l)
	if(l[i]+1 not in d or d[l[i]+1] == 0):
		d[l[i]] -= 1
		l[i] += 1
		d[l[i]] = 1 
	elif(d[l[i]] == 1):
		continue
	elif(l[i] > 1):
		d[l[i]] -= 1
		l[i] -= 1
		if(l[i] in d):
			d[l[i]] += 1
		else:
			d[l[i]] = 1 

#print(l)
s = len(set(l))
print(s)