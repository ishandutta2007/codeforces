from collections import *
s = input()
k = int(input())
n = len(s)//k
if(len(s)%k != 0):
	print("NO")
	exit(0)
for i in range(0,len(s),n):
	t = s[i:i+n]
	if(t != t[::-1]):
		print("NO")
		break
else:
	print("YES")