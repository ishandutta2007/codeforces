n = int(input())
l = list(map(int,input().split()))
pre = [0]
for i in range(n):
	pre.append(l[i] + pre[i])
q = int(input())
for y in range(q):
	l,r = map(int,input().split())
	print((pre[r] - pre[l-1])//10)