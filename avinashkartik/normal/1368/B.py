from collections import *
from math import *

k = int(input())
ct = [1 for i in range(10)]
s = "codeforces"
ans = ""
p,ind = 1,0
while(p < k):
	p //= ct[ind]
	ct[ind] += 1
	p *= ct[ind]
	ind = (ind+1)%10
for i in range(10):
	ans += s[i]*ct[i]
print(ans)