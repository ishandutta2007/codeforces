from math import *
from collections import *
n = int(input())
a = list(map(int,input().split()))
for i in range(n):
    a[i] = [a[i],i]
a.sort()
ct = 1
ans = [0 for i in range(n)]
dp = [1e18 for i in range(n)]
ans[1] = -1
ans[1] = -1
ans[2] = -1
dp[2] = a[2][0] - a[0][0]
dp[3] = a[3][0] - a[0][0]
dp[4] = a[4][0] - a[0][0]
for i in range(5,n):
    if(dp[i-3] + a[i][0] - a[i-2][0] > dp[i-4] + a[i][0] - a[i-3][0]):
        if(dp[i-5] + a[i][0] - a[i-4][0] > dp[i-4] + a[i][0] - a[i-3][0]):
            dp[i] = dp[i-4] + a[i][0] - a[i-3][0]
            ans[i] = i-4
        else:
            dp[i] = dp[i-5] + a[i][0] - a[i-4][0]
            ans[i] = i-5
    else:
        if(dp[i-5] + a[i][0] - a[i-4][0] > dp[i-3] + a[i][0] - a[i-2][0]):
            dp[i] = dp[i-3] + a[i][0] - a[i-2][0]
            ans[i] = i-3
        else:
            dp[i] = dp[i-5] + a[i][0] - a[i-4][0]
            ans[i] = i-5
#print(ans)
i = n-1
while(i > 0):
    prev = i
    i = ans[i]
    for j in range(prev,i,-1):
        ans[j] = str(ct)
    ct += 1
ans[0] = str(ct-1)
print(dp[n-1],ct-1)
b = [0 for i in range(n)]
for i in range(n):
    ind = a[i][1]
    b[ind] = ans[i]
print(" ".join(b))