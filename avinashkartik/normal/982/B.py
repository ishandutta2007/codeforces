n = int(input())
a = list(map(int,input().split()))
for i in range(n): a[i] = [a[i],i]
s = input()
ans = [0 for i in range(2*n)]
ext = []
a.sort()
i = 0
for t in range(2*n):
	if s[t] == '0':
		ans[t] = a[i][1]+1
		ext.append(a[i][1]+1)
		i += 1
	else:
		ans[t] = ext[-1]
		ext.pop()
print(*ans)