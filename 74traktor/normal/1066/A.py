t = int(input())
for i in range(t):
	L,v,l,r = map(int,input().split())
	q = L // v
	l1 = (l + v - 1) // v
	r1 = r // v
	print(q - r1 + l1 - 1)