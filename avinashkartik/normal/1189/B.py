n = int(input())
l = list(map(int,input().split()))
l.sort()
flag = 0
if(l[n-1] >= l[n-2] + l[n-3]):
	print("NO")
else:
	print("YES")
	for i in range(n-2):
		print(l[i],end = " ")
	print(l[n-1],l[n-2])