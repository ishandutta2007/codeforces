M=10**9+7
n=input()
s=[c=='(' for c in raw_input()]
m=len(s)
z=[[0,0]]
for v in s:
 a=z[-1][v]
 z[-1][v]=len(z)
 z+=[z[a][:]]
z[m]=[m,m]
dp=[[0]*(m+1) for _ in range(n+1)]
dp[0][0]=1
for _ in range(2*n):
 ndp=[[0]*(m+1) for _ in range(n+1)]
 for i in range(n+1):
  for j in range(m+1):
   if i>0:ndp[i-1][z[j][0]]=(ndp[i-1][z[j][0]]+dp[i][j])%M
   if i<n:ndp[i+1][z[j][1]]=(ndp[i+1][z[j][1]]+dp[i][j])%M
 dp=ndp
print(dp[0][m])