from collections import *
n = int(input())
cta,ctb = 0,0
for i in range(n):
	a,b = map(int,input().split())
	if(a > b): cta += 1
	elif(b > a): ctb += 1
if(cta > ctb):
	print("Mishka")
elif(cta < ctb):
	print("Chris")
else:
	print("Friendship is magic!^^")