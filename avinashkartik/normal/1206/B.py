n = int(input())
a = list(map(int,input().split()))
a.sort()
c = 0
cnt = 0
for i in range(n):
	if(a[i] < 0):
		c += (-1-a[i])
		cnt = i+1
	elif(a[i] == 0):
		cnt = 2
		c += 1
	else:
		c += (a[i]-1)
if(cnt % 2):
	c += 2
print(c)