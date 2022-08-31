from collections import *
from math import *

a,b = list(map(int,input().split()))
ans = [b]
while(b > a):
	if(b%10 == 1):
		b //= 10
	elif((b%10)&1):
		print("NO")
		exit(0)
	else:
		b //= 2
	ans.append(b)
if(a != b):
	print("NO")
else:
	print("YES")
	ans = ans[::-1]
	print(len(ans))
	print(*ans)