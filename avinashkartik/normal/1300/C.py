n = int(input())
a = list(map(int,input().split()))
ind = -1
for i in range(32,-1,-1):
	ct = 0
	x = 1<<i
	for j in range(n):
		if(a[j]&x == x):
			ct += 1
			if(ct == 1): ind = j
	if(ct == 1): break
	else: ind = -1
if(ind == -1):
	for i in a:
		print(i,end=" ")
else:
	print(a[ind],end = " ")
	for i in a:
		if(i == a[ind]): continue
		print(i,end=" ")