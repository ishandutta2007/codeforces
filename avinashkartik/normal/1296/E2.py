from math import *
n = int(input())
s = input()
pre = [0 for i in range(n)]
pre[0] = 1
prev = s[0]
lst = [-1 for i in range(26)]
lst[0] = s[0]
ct = 1
for i in range(1,n):
	for j in range(26):
		if(lst[j] == -1 or lst[j] <= s[i]):
			lst[j] = s[i]
			pre[i] = j+1
			ct = max(ct,j+1)
			break

print(ct)
for i in pre:
	print(i,end = " ")