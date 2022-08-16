from math import *
a,b = map(int,input().split())
lcm = a*b//gcd(a,b)
cta = lcm//a
ctb = lcm//b
if(a > b):
	ctb -= 1
else:
	cta -= 1
if(cta > ctb):
	print("Dasha")
elif(ctb > cta):
	print("Masha")
else:
	print("Equal")