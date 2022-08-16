n,x = map(int,input().split())
a = list(map(int,input().split()))
m = min(a)
f = x-1
for i in range(n):
	if(a[f] == m):
		st = f
		break
	f = (f-1)%n
c = m+1
ct = 0
for i in range(n):
	a[st] -= c
	ct += c
	if(st == x-1): c -= 1
	st = (st+1)%n
a[st] = ct-1
print(*a)