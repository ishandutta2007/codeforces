t = int(input())
for i in range(t):
	n,m = map(int,input().split())
	if(n-m == 1):
		print("NO")
	else:
		print("YES")