n, m = map(int, input().split())
a = [int(x) for x in input().split()]
c = sum(a)
if n == 1:
	print(0)
	exit(0)
a.sort()
res = 0
pocl = a[n - 1]
f = False
for i in range(n - 2, -1, -1):
	if pocl > 1:
		if a[i] >= pocl:
			res += 1
			pocl -= 1
			res += (a[i] - 1)
		else:
			f = True
			pocl = a[i]
			res += 1
			res += (a[i] - 1)
			pocl -= 1
	elif pocl == 1:
		if f:
			res += 1
		res += (a[i] - 1)
		pocl -= 1
	else:
		res += (a[i] - 1)
	#print(res, pocl)
print(res)