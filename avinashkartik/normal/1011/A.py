n,k = map(int,input().split())
s = input()
l = []
for i in s:
	l.append(ord(i)-ord('a'))
l = list(set(l))
l.sort()
a = [l[0]]
n = len(l)
for i in range(1,n):
	if l[i-1] in a:
		if l[i] - l[i-1] >= 2:
			a.append(l[i])
	else:
		a.append(l[i])
a.sort()
ct = 0
if len(a) < k:
	print(-1)
else:
	#print(l)
	#print(a)
	for i in range(k):
		ct += a[i]+1
	print(ct)