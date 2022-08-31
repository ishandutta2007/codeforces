t = int(input())
for y in range(t):
	n,k = map(int,input().split())
	ans = k//(n-1)*n + k%(n-1)
	if(k%(n-1) == 0): ans -= 1
	print(ans)