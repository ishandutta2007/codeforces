n = int(input())
a = list(map(int,input().split()))
m = -1
f = 0
for i in range(n-1):
    dif = abs(a[i]-a[i+1])
    if dif == 0:
        f = 1
        break
    if dif != 1:
        if m == -1:
            m = dif
        else:
            if m!= dif:
                f = 1
                break
if f :print('NO')
elif m == -1:
    print('YES')
    print(1,max(a))
else:
    #print('YES')
    mj = -1
    for i in a:
        mj = max(mj,(i-1)//m+1)
    f = 0
    for i in range(n-1):
        dif = abs(a[i]-a[i+1])    
        if dif == 1:
            #print(((a[i]-1)//m) , ((a[i+1]-1)//m))
            if ((a[i]-1)//m) != ((a[i+1]-1)//m):
                f = 1
                break
    if f :print('NO')
    else:
        print('YES')
        print(mj,m)