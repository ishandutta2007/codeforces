from math import *
from collections import *
t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	d = Counter(a)
	diff = len(d)
	same = 0
	for i in d.values():
		same = max(i,same)
	if(diff < same):
		print(diff)
	elif(diff == same):
		print(diff-1)
	else:
		print(same)