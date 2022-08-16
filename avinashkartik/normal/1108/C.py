from collections import *
from math import *

def calc(x):
	ct = 0
	for i in range(n):
		if(s[i] != x[i]):
			ct += 1
	return ct

n = int(input())
s = input()
t = "RGB"*n
ans = calc("RGB"*n)
if(ans > calc("RBG"*n)):
	ans = calc("RBG"*n)
	t = "RBG"*n
if(ans > calc("BGR"*n)):
	ans = calc("BGR"*n)
	t = "BGR"*n
if(ans > calc("BRG"*n)):
	ans = calc("BRG"*n)
	t = "BRG"*n
if(ans > calc("GBR"*n)):
	ans = calc("GBR"*n)
	t = "GBR"*n
if(ans > calc("GRB"*n)):
	ans = calc("GRB"*n)
	t = "GRB"*n
print(ans)
print(t[:n])