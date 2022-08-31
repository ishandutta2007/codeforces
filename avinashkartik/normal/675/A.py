from collections import *
a,b,c = list(map(int,input().split()))
if(c == 0):
	if(a == b): print("YES")
	else: print("NO")
elif(a%c == b%c):
	if (a >= b and c < 0) or (a <= b and c > 0): print("YES")
	else: print("NO")
else: print("NO")