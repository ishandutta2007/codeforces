from math import *
t = int(input())
a = []
k = 1
for i in range(38):
    a.append(k)
    k *= 3
a.append(k)
#print(a[-1])
for y in range(t):
    ct = [0 for i in range(39)]
    n = int(input())
    n1 = n
    while(n != 0):
        for i in range(39):
            if a[i] >= n:
                j = i-1
                break
        if a[j+1] == n:
            ct[j+1] += 1
            n = 0
        else:
            n -= a[j]
            ct[j] += 1
    l = -1
    #print(ct)
    key = 0
    for i in range(39):
        #print(i,l)
        if ct[i] == 0:
            if l == -1:
                l = i
        elif ct[i] == 2:
            ct[i] = 1
            l = -1
            key = 1
    ans = a[l]
    if l == -1 or key == 0:
        print(n1)
    else:
        for i in range(l,39):
            ans += ct[i]*a[i]
        print(ans)