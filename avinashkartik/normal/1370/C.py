from collections import *
from math import *

t = int(input())
for y in range(t):
	n = int(input())
	m = n
	if(n == 1):
		print("FastestFinger")
		continue
	if(n&1):
		print("Ashishgup")
		continue
	ct = 0
	while(n%2 == 0):
		ct += 1
		n //= 2
	if(ct == 1):
		if(m == 2):
			print("Ashishgup")
			continue
		else:
			i = 3
			cnt = 0
			while(i*i <= n):
				while(n%i == 0):
					cnt += 1
					n //= i
				i += 1
			if(n > 1): cnt += 1
			if(cnt == 1):
				print("FastestFinger")
				continue
			else:
				print("Ashishgup")
				continue
	if(n == 1):
		print("FastestFinger")
		continue
	else:
		print("Ashishgup")
		continue