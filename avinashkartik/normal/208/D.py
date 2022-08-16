n = int(input())
l = list(map(int,input().split()))
a = list(map(int,input().split()))
ans = [0 for i in range(5)]
ct = 0
for i in l:
	ct += i
	for j in range(4,-1,-1):
		if(ct >= a[j]):
			ans[j] += ct//a[j]
			ct %= a[j]
print(*ans)
print(ct)