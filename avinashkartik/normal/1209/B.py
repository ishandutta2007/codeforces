n = int(input())
s = list(input())
for i in range(n):
	s[i] = ord(s[i]) - ord('0')

a = [0 for i in range(n)]
b = [0 for i in range(n)]
for i in range(n):
	b[i],a[i] = map(int,input().split())
r = 10*9*8*7*6*5*4*3*2
max1 = s.count(1)
for i in range(10000):
	if(max1 == n):
		break
	for j in range(n):
		if(i >= a[j]):
			if((i-a[j])%b[j] == 0):
				s[j] = s[j]^1
	#print(s)
	u = s.count(1)
	if(u > max1):
		max1 = u
print(max1)