a = list(map(int,input().split()))
s = input()
ans = 0
for i in s:
	ans += a[int(i)-1]
print(ans)