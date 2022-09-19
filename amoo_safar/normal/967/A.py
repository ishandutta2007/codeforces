n,s = map(int,input().split())
a = []
for i in range(n):
    h,m = map(int,input().split())
    a.append(60*h + m)
a.append(10000000000)
if a[0] > s:
    print(0,0)
else:
    for i in range(n):
        if (a[i+1]-a[i] > 2*s+1):
            print((a[i]+s+1)//60,(1+a[i]+s)%60)
            break