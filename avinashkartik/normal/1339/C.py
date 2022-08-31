l = [(1<<(i+1))-1 for i in range(45)]
t = int(input())
for y in range(t):
	n = int(input())
	a = list(map(int,input().split()))
	ans = 0
	for i in range(n-1):
		if(a[i+1] >= a[i]):
			continue
		for j in range(45):
			#print(l[j])
			if(a[i+1] + l[j] >= a[i]):
				break
		ans = max(ans,j+1)
		a[i+1] = a[i]
	print(ans)