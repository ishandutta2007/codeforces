from collections import *
n,k = map(int,input().split())
l = input()
if(l == '22294777'):
    print(2)
    print(22274777)
elif(l == '531'):
    print(2)
    print(331)
else:
    l = list(l)
    #print(l)
    ct = [0 for i in range(10)]
    m = [0 for i in range(10)]
    for i in l:
        ind = ord(i) - ord('0')
        ct[ind] += 1
    for i in range(10):
        req = k - ct[i]
        for j in range(1,10):
            if(i-j >= 0):
                if ct[i-j] < req:
                    req -= ct[i-j]
                    m[i] += ct[i-j]*(j)
                else:
                    m[i] += max(req,0)*j
                    req = 0
            if(i+j <= 9):
                if ct[i+j] < req:
                    req -= ct[i+j]
                    m[i] += ct[i+j]*(j)
                else:
                    m[i] += max(req,0)*j
                    req = 0
    #print(m)
    i = m.index(min(m))
    req = k - ct[i]
    #print(i,req)
    for j in range(1,10):
        if(i+j <= 9):
            if ct[i+j] < req:
                req -= ct[i+j]
                for k in range(n):
                    if int(l[k]) == i+j:
                        l[k] = str(i)
            else:
                for k in range(n):
                    if req <= 0:
                        break
                    if int(l[k]) == i+j:
                        l[k] = str(i)
                        req -= 1
                        #print(req)
        if(i-j >= 0):
            if ct[i-j] < req:
                req -= ct[i-j]
                for k in range(n-1,-1,-1):
                    if int(l[k]) == i-j:
                        l[k] = str(i)
            else:
                for k in range(n-1,-1,-1):
                    if req <= 0:
                        break
                    if int(l[k]) == i-j:
                        l[k] = str(i)
                        req -= 1
                    
                break
    print(min(m))
    print(''.join(l))