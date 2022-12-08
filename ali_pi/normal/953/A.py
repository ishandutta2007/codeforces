l,r=(int(x)for x in raw_input().split())
ans=0
for i in range(35):
	for j in range(25):
		x=(2**i)*(3**j)
		if x>=l and x<=r :
			ans+=1
print(ans)