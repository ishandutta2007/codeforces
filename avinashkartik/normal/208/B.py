d = dict()
def mem(i,a):
	if(i == 1):
		print("YES")
		exit(0)
	if((i,a) in d):
		return
	b = list(a[::])
	if(a[i-2][0] == a[i-1][0] or a[i-2][1] == a[i-1][1]):
		b[i-2] = a[i-1]
		mem(i-1,tuple(b[:i-1]))
		b[i-2] = a[i-2]
	if(i > 3 and (a[i-4][0] == a[i-1][0] or a[i-4][1] == a[i-1][1])):
		b[i-4] = a[i-1]
		mem(i-1,tuple(b[:i-1]))
	d[(i,a)] = 0

n = int(input())
a = list(input().split())
mem(n,tuple(a))
print("NO")