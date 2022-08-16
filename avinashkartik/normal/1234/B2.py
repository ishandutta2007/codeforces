n,k = map(int,input().split())
d = dict()
l = list(map(int,input().split()))
q = [0 for i in range(k)]
ct = 0
top = k-1
for i in range(n):
	if(ct == k):
		if(l[i] not in d or d[l[i]] == 0):
			d[q[top]] = 0
			q[top] = l[i]
			top -= 1
			if(top == -1):
				top = k-1
			d[l[i]] = 1
	else:
		if(l[i] not in d or d[l[i]] == 0):
			q[k-1-ct] = l[i]
			ct += 1
			d[l[i]] = 1
	#print(q)
print(ct)
for i in range(k):
	ind = (top+1)%k
	if(q[ind] != 0):
		print(q[ind],end = " ")
	top = (top+1)%k
print()