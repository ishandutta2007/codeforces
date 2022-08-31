from math import *
from collections import *
import sys
sys.setrecursionlimit(10**9)
n,k = map(int,input().split())
ct1 = ct2 = 0
ans1 = ans2 = -1
for i in range(k+1):
	print("?",end = " ")
	for j in range(k+1):
		if(i == j): continue
		print(j+1,end  = " ")
	print()
	ind,ans = map(int,input().split())
	if(ans1 == -1):
		ans1 = ans
		ct1 += 1
	elif(ans == ans1):
		ct1 += 1
	elif(ans2 == -1):
		ans2 = ans
		ct2 += 1
	else:
		ct2 += 1
	sys.stdout.flush()
	#print(ans1,ct1)
if(ans1 > ans2):
	print("!",k+1-ct2)
else:
	print("!",k+1-ct1)