from math import *
from collections import *
s = input()
stack = []
ct = 0
for i in s:
	if(stack != [] and i == stack[-1]):
		stack.pop()
		ct += 1
	else:
		stack.append(i)
if(ct%2 == 0):
	print("No")
else:
	print("Yes")