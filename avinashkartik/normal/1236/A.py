t = int(input())
for y in range(t):
	a,b,c = map(int,input().split())
	ct = 0
	ct += min(b,c//2)
	b -= ct
	ct += min(a,b//2)
	print(ct*3)