from collections import *
t = int(input())
for y in range(t):
	n,k = map(int,input().split())
	a = list(map(int,input().split()))
	c = Counter(a)
	if(len(c) > k):
		print(-1)
		continue
	ct = k-len(c)
	b = []
	for i in c.keys():
		b.append(i)
	for i in range(1,101):
		if ct == 0: break
		if i not in c:
			b.append(i)
			ct -= 1
	b = b*100
	print(len(b))
	for i in b:
		print(i,end = " ")
	print()