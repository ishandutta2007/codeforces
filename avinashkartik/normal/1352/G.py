t = int(input())
for y in range(t):
	n = int(input())
	ans = []
	for i in range(n-(n%2==0),0,-2):
		ans.append(i)
	ans.append(4)
	ans.append(2)
	for i in range(6,n+1,2):
		ans.append(i)
	if(n <= 3):
		print(-1)
	else:
		print(*ans)