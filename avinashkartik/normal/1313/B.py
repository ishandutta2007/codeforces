t = int(input())
for j in range(t):
	n,x,y = map(int,input().split())
	print(max(1,min(n,x+y-n+1)), min(n,x+y-1))