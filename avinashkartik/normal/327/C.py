mod = 10**9+7
def fastmod(x,y):
	res = 1
	while(y > 0):
		if(y&1): res = (res*x)%mod
		x = (x*x)%mod
		y //= 2
	return res

s = input()
n = len(s)
k = int(input())
p = ((fastmod(2,n*k)-1)*fastmod(fastmod(2,n)-1,mod-2))%mod
ans = 0
for i in range(n):
	if(s[i] == '0' or s[i] == '5'):
		ans = (ans+p)%mod
	p = (p*2)%mod
print(ans)