t = int(input())
for y in range(t):
	n,m = map(int,input().split())
	mid = 2**(m-1)-1
	d = dict()
	for i in range(n):
		x = int(input(),2)
		d[x] = 1
		if(i%2 == 0):
			if(x <= mid):
				mid += 1
				while(mid in d):
					mid += 1
		else:
			if(x >= mid):
				mid -= 1
				while(mid in d):
					mid -= 1
	t = ""
	for i in range(m-1,-1,-1):
		x = 2**i
		if(mid&x):
			t += '1'
		else:
			t += '0'
	print(t)