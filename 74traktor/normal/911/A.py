n = int(input())
a = [int(x) for x in input().split()]
r = n
mi = a[0]
imin = 0
r = -1
for i in range(1,n):
	if a[i] == a[imin]:
		if (r == -1 or (i - imin) < r):
			r = i - imin
		imin = i
	if a[i] < a[imin]:
		imin = i
		r = -1
print(r)