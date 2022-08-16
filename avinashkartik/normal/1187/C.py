n,q = map(int,input().split())
a = [0 for i in range(n+1)]
d = []
for i in range(q):
	t,l,r = map(int,input().split())
	if(t == 1):
		a[l] += 1
		a[r] -= 1
	else:
		d.append([l,r])
#print(a)
for i in range(1,n+1):
	a[i] = a[i-1] + a[i]
#print(a)
for i in d:
	flag = 0
	for j in range(i[0],i[1]):
		if a[j] == 0:
			flag = 1
			break
	if flag == 0:
		print("NO")
		break
else:
	print("YES")
	ct = n
	print(ct,end = " ")
	for i in range(1,n):
		if(a[i] == 0):
			ct -= 1
		print(ct,end = " ")
	print()