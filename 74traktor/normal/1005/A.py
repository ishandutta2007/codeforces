n = int(input())
a = [int(x) for x in input().split()]
ans = []
for i in range(n):
	if a[i] == 1 and i != 0:
		ans.append(a[i- 1])
ans.append(a[n - 1])
print(len(ans))
for x in ans:
	print(x, end = ' ')