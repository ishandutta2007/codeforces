t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	o = e = 0
	for i in a:
		if(i&1): o += 1
		else: e += 1
	if(o&1):
		print("YES")
		continue
	if(o > 0 and o != n):
		print("YES")
		continue
	print("NO")