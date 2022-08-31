n = int(input())
a = list(map(int,input().split()))
a.sort()
ans = a[-1]-a[0]
ct = a.count(a[0])*a.count(a[-1])
if(ans == 0):
	ct = a.count(a[0])*(a.count(a[0])-1)//2
print(ans,ct)