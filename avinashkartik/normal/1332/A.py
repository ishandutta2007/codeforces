t = 1
t = int(input())
for y in range(t):
	a,b,c,d = map(int,input().split())
	x,y,x1,y1,x2,y2 = map(int,input().split())
	f = 0
	if(a > b):
		if a-b > x-x1 or (x2-x1 == 0 and a != 0): f = 1
	else:
		if b-a > x2-x or (x2-x1 == 0 and b != 0): f = 1
	if(c > d):
		if c-d > y-y1 or (y2-y1 == 0 and c != 0): f = 1
	else:
		if d-c > y2-y or (y2-y1 == 0 and d != 0): f = 1
	if(f == 0):
		print("Yes")
	else:
		print("No")