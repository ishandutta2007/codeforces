p=10**9+7
n,m=raw_input().split()
n=int(n)
m=int(m)
a=raw_input().split()
b=raw_input().split()
a=[int(k) for k in a]
b=[int(k) for k in b]
invm=pow(m,p-2,p)
inv2=pow(2,p-2,p)
ans=0
for i in reversed(range(n)):
	if a[i]==0 and b[i]==0:
		ans=(((inv2*invm)%p)*(m-1)+invm*ans)%p
	if a[i]==0 and b[i]!=0:
		ans= ((m-b[i])*invm+invm*ans)%p
	if a[i]!=0 and b[i]==0:
		ans= ((a[i]-1)*invm+invm*ans)%p
	if a[i]!=0 and b[i]!=0:
		if a[i]>b[i]:
			ans= 1
		elif b[i]>a[i]:
			ans= 0
		else:
			ans= ans
print(ans)