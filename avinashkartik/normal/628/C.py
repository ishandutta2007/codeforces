from math import *
n,k = map(int,input().split())
s = list(input())
maxx = 0
ans = s[::]
for i in range(n):
	if(s[i] <= 'm'):
		maxx += ord('z') - ord(s[i])
		ans[i] = 'z'
	else:
		maxx += ord(s[i]) - ord('a') 
		ans[i] = 'a'
i = 0
while(i < n and maxx != k):
	x = ord(ans[i])
	while(x != ord(s[i])):
		if(ans[i] == 'a'):
			x += 1
		else:
			x -= 1
		maxx -= 1
		if(maxx == k):
			break
	ans[i] = chr(x)
	i += 1
if(maxx != k):
	print(-1)
else:
	print("".join(ans))