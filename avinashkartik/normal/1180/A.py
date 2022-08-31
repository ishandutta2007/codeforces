n = int(input())
s = 2*n-1
ans = 0 - s
for i in range(1,s+1,2):
	ans += 2*i
print(ans)