n = int(input())
a = []
for i in range(n):
	x = sum(list(map(int,input().split())))
	a.append([x,i])
a.sort()
ans = [n for i in range(n)]
for i in range(n):
	ans[a[i][1]] = i+1
for i in ans:
	print(i,end = " ")
print()