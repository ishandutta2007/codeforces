t = int(input())
for y in range(t):
	a,b,c,n = map(int,input().split())
	l = [a,b,c]
	l.sort()
	ct = 3*l[2]-sum(l)
	if(n < ct or n%3 != ct%3):
		print("NO")
	else:
		print("YES")