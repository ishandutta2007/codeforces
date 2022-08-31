n = int(input())
a = list(map(int,input().split()))
ans = []
for i in range(n-1,-1,-1):
	if(a[i] not in ans):
		ans.append(a[i])
print(len(ans))
print(*ans[::-1])