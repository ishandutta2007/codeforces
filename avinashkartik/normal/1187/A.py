q = int(input())
for i in range(q):
	n,s,t = map(int,input().split())
	print(max(s,t) - (s+t-n) + 1)