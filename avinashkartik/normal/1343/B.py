from math import *
test = int(input())
for test_case in range(test):
	n = int(input())
	ans = []
	s = 0
	for i in range(1,n//2+1):
		ans.append(i*2)
		s += i*2
	for i in range(1,n//2):
		ans.append(i*2-1)
		s -= i*2-1
	if(s%2 == 0):
		print("NO")
		continue
	else:
		ans.append(s)
		print("YES")
		for i in ans:
			print(i,end = " ")
		print()