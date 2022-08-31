N = 2*(10**6)
i = 2
p = [0 for i in range(N)]
while(i*i <= N):
	if(p[i] == 0):
		for j in range(i*i,N,i):
			p[j] = 1
	i += 1
a = []
for i in range(2,N):
	if(p[i] == 0):
		a.append(i)
n = int(input())
l = list(map(int,input().split()))
d = dict()
ans = []
for i in range(n):
	v = []
	y = l[i]
	j = 2
	f = 1
	while(j*j <= l[i]):
		if(l[i]%j == 0):
			if(j in d):
				f = 0
				break
			v.append(j)
			while(l[i]%j == 0):
				l[i] /= j
		j += 1
	if(l[i] > 1):
		if(l[i] in d):
			f = 0
		v.append(l[i])
	if(f == 1):
		ans.append(y)
		for x in v:
			d[x] = 1
	else:
		for x in range(y,N):
			j = 2
			f = 1
			l[i] = x
			while(j*j <= l[i]):
				if(l[i]%j == 0):
					if(j in d):
						f = 0
						break
					while(l[i]%j == 0):
						l[i] /= j
				j += 1
			if(l[i] > 1):
				if(l[i] in d):
					f = 0
			if(f == 1):
				ans.append(x)
				break
		break
j = 2
x = ans[-1]
while(j*j <= x):
	if(x%j == 0):
		d[j] = 1
		while(x%j == 0):
			x /= j
	j += 1
if(x > 1):
	d[x] = 1
sz = len(ans)
for i in a:
	if(sz == n):
		break
	if(i not in d):
		ans.append(i)
		sz += 1
for i in ans:
	print(i,end = " ")
print()