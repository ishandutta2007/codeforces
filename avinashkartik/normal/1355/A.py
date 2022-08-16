def find(n):
	while(n > 0):
		if n%10 == 0:
			return False
		n //= 10
	return True
def maxx(n):
	m = 0
	while(n > 0):
		m = max(m,n%10)
		n //= 10
	return m
def minn(n):
	m = 10
	while(n > 0):
		m = min(m,n%10)
		n //= 10
	return m
t = int(input())
for y in range(t):
	n,k = map(int,input().split())
	while(find(n)):
		if(k == 1):
			break
		a = maxx(n)
		b = minn(n)
		n += a*b
		k -= 1
	print(n)