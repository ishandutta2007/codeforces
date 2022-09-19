n,h = map(int,input().split())
a = list(map(int,input().split()))
a = [h-i for i in a]
if min(a) < 0 or a[0] > 1 or a[-1] > 1:
    print(0)
else:
    t = 1
    for i in range(1,n):
        dif = a[i-1]-a[i]
        if dif >1 or dif <-1:t = 0
        else:
            if dif == 0:t*=(a[i-1]+1)
            elif dif == 1:t*=(a[i-1])
        #print(t)
        t%=(1000000000+7)
    print(t)