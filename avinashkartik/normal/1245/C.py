from math import *
from collections import *

N = 100000
mod = int(1e9 + 7)
dp = [0 for i in range(N)]
dp[1] = 1
dp[2] = 2
for i in range(3,N):
    dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod

s = input()
if(s.find('m') != -1 or s.find('w') != -1):
    print(0)
else:
    ans = 1
    n = len(s)
    i = 0
    while(i < n):
        ct = 0
        if s[i] == 'n':
            while(i < n and s[i] == 'n'):
                i += 1
                ct += 1
            ans = ((ans%mod)*(dp[ct]%mod))%mod
        elif s[i] == 'u':
            while(i < n and s[i] == 'u'):
                i += 1
                ct += 1
            ans = ((ans%mod)*(dp[ct]%mod))%mod
        else:
            i += 1
        #print(ct)
    print(int(ans%mod))