t = int(input())
for y in range(t):
	r,c = map(int,input().split())
	if(r == 1 or c == 1 or r*c == 4):
		print("YES")
	else:
		print("NO")