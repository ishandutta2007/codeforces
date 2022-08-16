n = int(input())
l = list(map(int,input().split()))
s = l[-1]
prev = s
for i in range(n-2,-1,-1):
	if(prev == 0):
		break
	if(l[i] >= prev):
		prev -= 1
		s += prev
	else:
		prev = l[i]
		s += prev
print(s)