n,m,k=map(int,input().split())
#for k in range(n*m):
#    print(k)
if True:
    if k<n:
        print(k+1,1)
    elif n+m-1>k:
        print(n,k-n+2)
    else:
        k-=n+m-1
        x,y=divmod(k,(m-1)*2)
        if y<m-1:
            print(n-1-x*2,m-y)
        else:
            print(n-2-x*2,2+y-m+1)
#    print()