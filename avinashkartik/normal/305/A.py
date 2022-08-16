from collections import *
from math import *

d = dict()

n = int(input())
a = list(map(int,input().split()))
d["000"],d["001"],d["010"],d["011"],d["100"],d["101"],d["110"],d["111"] = [],[],[],[],[],[],[],[]
for i in range(n):
	x = ""
	y = a[i]
	while(a[i]):
		x += str(int(a[i]%10 != 0))
		a[i] //= 10
	while(len(x) < 3): x += '0'
	x = x[::-1]
	d[x] = [y]
fans,ans = [],[]
ans.extend(d["100"]+d["010"]+d["001"]+d["000"])
if(len(fans) < len(ans)):
	fans = ans
ans = []
ans.extend(d["100"]+d["011"]+d["000"])
if(len(fans) < len(ans)):
	fans = ans
ans = []
ans.extend(d["110"]+d["001"]+d["000"])
if(len(fans) < len(ans)):
	fans = ans
ans = []
ans.extend(d["101"]+d["010"]+d["000"])
if(len(fans) < len(ans)):
	fans = ans
ans = []
ans.extend(d["111"]+d["000"])
if(len(fans) < len(ans)):
	fans = ans
print(len(fans))
print(*fans)