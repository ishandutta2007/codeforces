from math import *
n = int(input())
l1 = list(input())
l2 = list(input())
ca = 0
for i in range(n):
	if(l1[i] == 'a'):
		ca += 1
	if(l2[i] == 'a'):
		ca += 1
if(ca %2 != 0):
	print(-1)
else:
	ab = []
	ba = []
	for i in range(n):
		if(l1[i] == 'a' and l2[i] == 'b'):
			ab.append(i+1)
		if(l1[i] == 'b' and l2[i] == 'a'):
			ba.append(i+1)
	count = ceil(len(ab)/2) + ceil(len(ba)/2)
	print(count)
	c = d = -1
	#print(ab,ba)
	for i in range(0,len(ab),2):
		if(i == len(ab) - 1):
			c = ab[i]
		else:
			print(ab[i],ab[i+1])
			
	for i in range(0,len(ba),2):
		if(i == len(ba) - 1):
			d = ba[i]
		else:
			print(ba[i],ba[i+1])
			
	if(c != -1):
		print(c,c)
		print(c,d)