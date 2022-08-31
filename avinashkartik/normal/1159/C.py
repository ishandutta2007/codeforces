from collections import *
from math import *
n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
a.sort()
b.sort()
j = m-1
ans = 0
if a[-1] > b[0]:
    print(-1)
else:
    for i in range(n-1,-1,-1):
        ct = 0
        if(j >= 0):
            while(j >= 0 and a[i] <= b[j]):
                if(j == 0 and i == n-1):
                    ans += a[i]
                    if(a[i] != b[j]):
                        ct += 1
                        break
                else:
                    ans += b[j]
                ct += 1
                j -= 1
        #print(ans,ct)
        ans += (m-ct)*a[i]
    print(ans)