from collections import *
n = int(input())
a = list(map(int,input().split()))
c = Counter(a)
for i in range(len(a)):
	if(c[a[i]] > 2):
		print("NO")
		exit(0)
a.sort(reverse = True)
b = []
c = []
for i in range(n):
	if(len(b) == 0 or b[-1] != a[i]):
		b.append(a[i])
	else:
		c.append(a[i])
b = b[::-1]
print("YES")
print(len(b))
print(*b)
print(len(c))
print(*c)