from collections import *
n,k = map(int,input().split())
s = input()
ind = n
for i in range(1,n):
	if(s[:n-i] == s[i:]):
		ind = i
		break
t = s+(s[n-ind:])*(k-1)
print(t)