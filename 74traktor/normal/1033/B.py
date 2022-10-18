import math

def pr(x):
	if x <= 1:
		return False
	p = int(math.sqrt(x)) + 1
	for i in range(2,p):
		if x % i == 0:
			return False
	return True


t = int(input())
for i in range(t):
	x,y = map(int,input().split())
	if x != y + 1:
		print("NO")
	else:
		if pr(x + y):
			print("YES")
		else:
			print("NO")