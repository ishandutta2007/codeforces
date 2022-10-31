n = int(raw_input())

from math import sqrt

ans = []
pp = 1
for i in xrange(64):
	pp *= 2
	d = (pp - 3) * (pp - 3) + 8*n
	ds = int(sqrt(d))
	ds = max(0, ds - 500);
	for i in xrange(1000):
		if ds*ds == d:
			break
		ds += 1
	if ds*ds == d:
		x1 = (-(pp-3) + ds)
		x2 = (-(pp-3) - ds)
		if x1 > 0:
			if x1 % 2 == 0:
				x1 = x1 / 2
				if x1 % 2 == 0:
						continue
				curr = (x1 - 1) * x1 / 2
				while curr < n:
					curr = curr + x1
					x1 = x1 * 2
				if curr == n:
					ans.append(x1)
					#print curr
		if x2 > 0:
			if x2 % 2 == 0:
				x2 = x2 / 2
				curr = (x2 - 1) * x2 / 2
				if x2 % 2 == 0:
						continue
				while curr < n:
					curr = curr + x2
					x2 = x2 * 2
				if curr == n:
					ans.append(x2)
					#print curr

x = 2
curr = 0
for i in xrange(64):
	curr = curr + x/2
	if curr == n:
		ans.append(x)
	x = x*2	
					
					
ans = sorted(set(ans))

if len(ans) == 0:
	print -1

for i in ans:
	print i