from math import *
t = int(input())
for y in range(t):
	n = int(input())
	l1 = list(input())
	l2 = list(input())
	s = 0
	for i in range(n):
		if(s == 0):
			if(l1[i] == '1' or l1[i] == '2'):
				s = 0
			elif(l2[i] == '3' or l2[i] == '4' or l2[i] == '5' or l2[i] == '6'):
				s = 1
			else:
				s = 0
				break
		else:
			if(l2[i] == '1' or l2[i] == '2'):
				s = 1
			elif(l1[i] == '3' or l1[i] == '4' or l1[i] == '5' or l1[i] == '6'):
				s = 0
			else:
				s = 0
				break
	if(s == 1):
		print("YES")
	else:
		print("NO")