t = int(input())
for y in range(t):
	n,s = list(map(int,input().split()))
	a = list(map(int,input().split()))
	m = -1
	for i in range(n):
		s -= a[i]
		if(m == -1 or a[m] < a[i]): m = i
		if(s < 0 and m != n):
			print(m+1)
			break
	else:
		print(0)