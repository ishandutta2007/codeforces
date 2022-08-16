n = int(input())
l = list(map(int,input().split()))
if (n % 2) == 1:
	flag = 1
else:
	flag = 0
for i in range(n):
	if(l[i] >= 0):
		l[i] = -(l[i]+1)
if(flag == 1):
	l[l.index(min(l))] = -(l[l.index(min(l))]+1)
for i in l:
	print(i,end = " ")
print()