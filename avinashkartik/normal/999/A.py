n,k = map(int,input().split())
a = list(map(int,input().split()))
i = 0
while(i < n):
	if(a[i] > k):
		break
	i += 1
ans = i
i = n-1
while(i > -1):
	if(a[i] > k):
		break
	i -= 1
ans += n-1-i
print(min(ans,n))