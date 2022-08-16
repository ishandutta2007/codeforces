from collections import *
t = int(input())
for y in range(t):
	n,k = map(int,input().split())
	s = list(input())
	s.sort()
	ans = ["" for i in range(k)]
	j,f = 0,1
	for i in range(n):
		ans[j] += s[i]
		if(j != 0 and s[i] != s[i-1]): f = 0
		if(i != n-1): j = (j+1)%k
		if(i == n-1):
			x = "".join(s[k-1:])
			ans[j] = min(ans[j],x)
		if(j == 0 and f == 0):
			j = k-1
			if(i >= k):
				x = "".join(s[k-1:])
				ans[j] = min(ans[j],x)
			break
	print(ans[j])