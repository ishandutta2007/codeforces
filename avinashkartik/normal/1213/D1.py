n,k = map(int,input().split())
l = list(map(int,input().split()))
l.sort()
d = dict()
c = 0
f = 0
a = [0 for i in range(200001)]
min1 = -1
while(l[-1] != 0):
	for i in range(f,len(l)):
		if l[i] in d:
			d[l[i]] += 1
		else:
			d[l[i]] = 1
		a[l[i]] += c
		if(d[l[i]] >= k):
			#print(min1,l[i],d[l[i]],a[l[i]])
			if(min1 == -1):
				min1 = a[l[i]]
			else:
				min1 = min(min1,a[l[i]])
		if(l[i] == 0):
			f = i+1
		l[i] = l[i]//2
	#print(l)
	c += 1
print(min1)