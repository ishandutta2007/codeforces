t = int(input())
for y in range(t):
	n,m = map(int,input().split())
	if(n%m == 0): print("YES")
	else: print("NO")