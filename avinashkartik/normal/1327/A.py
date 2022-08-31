t = int(input())
for y in range(t):
	n,x = map(int,input().split())
	if(n >= x*x and n%2 == x%2):
		print("YES")
	else:
		print("NO")