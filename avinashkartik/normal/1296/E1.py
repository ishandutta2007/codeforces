from math import *
n = int(input())
s = input()
pre = '0'
prev = s[0]
lst = -1
for i in range(1,n):
	if(s[i] >= prev):
		prev = s[i]
		pre += '0'
	else:
		pre += '1'
		if(lst != -1):
			if(s[i] < lst):
				print("NO")
				exit(0)
		lst = s[i]
print("YES")
print(pre)