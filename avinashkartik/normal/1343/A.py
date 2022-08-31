from math import *
test = int(input())
for test_case in range(test):
	n = int(input())
	ct = 3
	p = 2
	while(1):
		if(n%ct == 0):
			print(n//ct)
			break
		p *= 2
		ct += p