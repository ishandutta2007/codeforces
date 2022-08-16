n,k = map(int,input().split())
d = dict()
l = list(map(int,input().split()))
q = [0 for i in range(k)]
ct = 0
for i in range(n):
	if(ct == k):
		if(l[i] not in d or d[l[i]] == 0):
			d[q[k-1]] = 0
			del(q[k-1])
			q.insert(0,l[i])
			d[l[i]] = 1
	else:
		if(l[i] not in d or d[l[i]] == 0):
			q[k-1-ct] = l[i]
			ct += 1
			d[l[i]] = 1
	#print(q)
print(ct)
for i in range(k):
	if(q[i] != 0):
		print(q[i],end = " ")
print()