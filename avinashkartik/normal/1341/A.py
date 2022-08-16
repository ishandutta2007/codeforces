t = int(input())
for y in range(t):
	n,a,b,c,d = map(int,input().split())
	lb = n*(a-b)
	rb = n*(a+b)
	if(lb > (c+d) or rb < (c-d)):
		print("No")
	else:
		print("Yes")