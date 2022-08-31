n = int(input())
x = int(input())
y = 7-x
for i in range(n):
	a,b = map(int,input().split())
	if(a+b == 7 or a == x or a == y or b == x or b == y):
		print("NO")
		break
else:
	print("YES")