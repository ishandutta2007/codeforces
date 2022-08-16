from collections import *
t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	b = list(map(int,input().split()))
	ca = Counter(a)
	cb = Counter(b)
	if(ca != cb):
		print("No")
		continue
	vis = [0 for i in range(n)]
	for i in range((n+1)//2):
		f = 1
		for j in range(n):
			if(vis[j] == 1):
				continue
			if(b[j] == a[i] and b[n-1-j] == a[n-1-i]):
				vis[j] = 1
				vis[n-1-j] = 1
				f = 0
				break
		if(f == 1):
			print("No")
			break
	else:
		print("Yes")