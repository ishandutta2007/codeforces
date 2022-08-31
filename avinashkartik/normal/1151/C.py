l,r = map(int,input().split())
a = [i for i in range(61)]
l2 = r2 = 0
for i in range(61,-1,-1):
    if(pow(2,i) <= l):
        l2 = i+1
        break
for i in range(61,-1,-1):
    if(pow(2,i) <= r):
        r2 = i+1
        break

if(l2%2 == 0):
    le = lo = 0
    for i in range(1,l2,2):
        le += pow(2,i)

    le -= pow(2,l2) - l

    for i in range(0,l2-1,2):
        lo += pow(2,i)
if(l2%2 == 1):
    lo = le = 0
    for i in range(0,l2,2):
        lo += pow(2,i)

    lo -= pow(2,l2) - l

    for i in range(1,l2-1,2):
        le += pow(2,i)

if(r2%2 == 0):
    re = ro = 0
    for i in range(1,r2,2):
        re += pow(2,i)

    re -= pow(2,r2) - r -1

    for i in range(0,r2-1,2):
        ro += pow(2,i)
if(r2%2 == 1):
    ro = re = 0
    for i in range(0,r2,2):
        ro += pow(2,i)

    ro -= pow(2,r2) - r -1

    for i in range(1,r2-1,2):
        re += pow(2,i)
mod = pow(10,9) + 7
so = ((ro%mod)*(ro%mod))%mod - ((lo%mod)*(lo%mod))%mod
se = ((re%mod)*((re+1)%mod))%mod - ((le%mod)*((le+1)%mod))%mod
print((so+se)%mod)