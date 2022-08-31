n,k = map(int,input().split())
a = list(input())
b = [0 for i in range(n)]
for i in range(k):
	for j in range(i,n,k):
		b[j] = a[i]
if(int("".join(b)) < int("".join(a))):
	i = k-1
	while(i >= 0 and a[i] == '9'):
		a[i] = '0'
		i -= 1
	if(i != -1):
		for j in range(i,n,k):
			b[j] = str(int(a[i])+1)
		for ii in range(k):
			if ii == i: continue
			for j in range(ii,n,k):
				b[j] = a[ii]
	else:
		for i in range(k):
			for j in range(i,n,k):
				if(i == 0): b[j] = '1'
				else: b[j] = 0
		b.append(b[n-k])
	print(len(b))
	print("".join(b))
else:
	print(len(b))
	print("".join(b))