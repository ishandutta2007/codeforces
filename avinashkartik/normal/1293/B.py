n = int(input())
ans = 1
for i in range(1,n):
	ans += 1/(i+1)
print(ans)