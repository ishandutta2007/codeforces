n,p,k = map(int,input().split())
l = list(map(int,input().split()))
d = dict()
for y in range(n):
	x = pow(l[y],4) - l[y]*(k)
	if(x%p not in d):
		d[x%p] = 1
	else:
		d[x%p] += 1
ct = 0
#print(d)
for k,v in d.items():
	ct += v*(v-1)//2
print(ct)