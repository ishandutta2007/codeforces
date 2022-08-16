t = int(input())
for y in range(t):
	n,k = map(int,input().split())
	ans = []
	f = 1
	if(n&1 == k&1):
		for i in range(k-1):
			ans.append(1)
		ans.append(n-k+1)
		if ans[-1] < 0:
			f = 0
	elif(n%2 == 0):
		for i in range(k-1):
			ans.append(2)
		ans.append(n-2*(k-1))
		if ans[-1] <= 0:
			f = 0
	else:
		f = 0
	if(f == 0):
		print("NO")
	else:
		print("YES")
		print(*ans)