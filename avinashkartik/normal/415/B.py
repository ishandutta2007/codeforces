from math import *
n,a,b = list(map(int,input().split()))
l = list(map(int,input().split()))
for i in l:
	x = i-ceil(((i*a//b)*b)/a)
	print(x,end = " ")
print()