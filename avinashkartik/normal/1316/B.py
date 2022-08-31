from math import *
test = int(input())
for y in range(test):
	n = int(input())
	s = input()
	ans = s
	k = 1
	for i in range(1,n+1):
		if(i%2 != n%2): t = s[i:]+s[:i][::-1]
		else: t = s[i:]+s[:i]
		if(t < ans):
			ans = t
			k = i+1
	print(ans)
	print(k)