n,s = map(int,input().split())
ans = []
d = s//n
for i in range(n):
	if(i < s%n):
		ans.append(d+1)
	else:
		ans.append(d)
x = min(ans)
if(x == 1):
	print("NO")
else:
	print("YES")
	print(*ans)
	print(x-1)