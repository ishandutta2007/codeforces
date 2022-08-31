from math import *
from collections import *
def mul(a,b):
    return ((a%mod)*(b%mod))%mod

mod = int(1e9 + 7)
n,l,r = map(int,input().split())
l -= 1
s = [0,0,0]
s[0] = r//3-l//3;
s[1] = (r+2)//3-(l+2)//3;
s[2] = (r+1)//3-(l+1)//3;

dp = [[0,0,0] for i in range(n+1)]
dp[1][0] = s[0]
dp[1][1] = s[1]
dp[1][2] = s[2]
for i in range(1,n+1):
    for j in range(3):
        for k in range(3):
            if (k+j)%3 == 1:
                dp[i][1] = (dp[i][1]%mod + mul(dp[i-1][j],s[k])%mod)%mod
            elif (k+j)%3 == 2:
                dp[i][2] = (dp[i][2]%mod + mul(dp[i-1][j],s[k])%mod)%mod
            elif (k+j)%3 == 0:
                dp[i][0] = (dp[i][0]%mod + mul(dp[i-1][j],s[k])%mod)%mod
    #print(dp[i])

print(dp[n][0]%mod)