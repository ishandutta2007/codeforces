n,u = map(int,input().split())
a = list(map(int,input().split()))
i = 0
j = 1
f = 1
ma = -1
while not((i==j) and (i==n-1)):
    if j<=i:
        j+=1
    if j < n-1:
        if a[j+1]-a[i] <= u:
            j+=1
        else:
            if j-i >= 2:
                f=0
                #print(i,j)
                ma = max(ma,(a[j]-a[i+1])/(a[j]-a[i]))
            i+=1
    else:
        if j-i >= 2:
            f=0
            #print(i,j)
            ma = max(ma,(a[j]-a[i+1])/(a[j]-a[i]))
        i+=1
if f:print(-1)
else:print(ma)