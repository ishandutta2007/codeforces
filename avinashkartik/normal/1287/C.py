from math import *
n = int(input())
a = list(map(int,input().split()))
o = e = 0
if(n == 1):
	print(0)
	exit(0)
for i in a:
	if(i == 0): continue
	if(i&1): o += 1
	else: e += 1
o = ceil(n/2) - o
e = n//2 - e 
l1 = l2 = 0
il1 = il2 = 0
ans = 0
ct = []
ect = []
for i in range(1,n):
	if(a[i] != 0 and a[i-1] != 0):
		if(a[i]%2 != a[i-1]%2):
			ans += 1
i = 0
while(i < n):
	st = i-1
	while(i < n and a[i] == 0):
		i += 1
	end = i
	l = end - st - 1
	if(l > 0):
		if(st == -1):
			l1 = l
			il1 = end
		elif(end == n):
			l2 = l
			il2 = st
		elif(a[st]%2 != a[end]%2):
			ans += 1
		else:
			if(a[st]%2 == 0):
				ect.append(l)
			else:
				ct.append(l)
	#print(st,end,l,ans)
	i += 1
ct.sort()
for i in ct:
	if(i <= o):
		o -= i
	else:
		ans += 2
ect.sort()
for i in ect:
	if(i <= e):
		e -= i
	else:
		ans += 2
if(l1):
	if(l1 == n):
		print(1)
		exit(0)
	if(a[il1]%2 == 0):
		if(e >= l1):
			e -= l1
		else:
			ans += 1
	else:
		if(o >= l1):
			o -= l1
		else:
			ans += 1
if(l2):
	if(a[il2]%2 == 0):
		if(e >= l2):
			e -= l2
		else:
			ans += 1
	else:
		if(o >= l2):
			o -= l2
		else:
			ans += 1
print(ans)