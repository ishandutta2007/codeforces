mod = 998244353
n,m,l,r = map(int, input().split())
if(n*m % 2 == 1):
	print(pow(r-l+1,n*m,mod))
elif((r-l+1)%2 == 1):
	print(((pow(r-l+1,n*m,mod)+1)*(mod+1)//2)%mod)
else:
	print(((pow(r-l+1,n*m,mod))*(mod+1)//2)%mod)