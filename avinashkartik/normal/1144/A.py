from collections import *
n = int(input())
for i in range(n):
	s = list(input())
	s.sort()
	for i in range(len(s)-1):
		if(ord(s[i])+1 != ord(s[i+1])):
			print("No")
			break
	else:
		print("Yes")