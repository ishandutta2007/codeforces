k,n,s,p=list(map(int,input().split()))

ss=n//s
if n%s!=0:
    ss+=1

if (ss*k)%p==0:
    print(ss*k//p)
else:
    print(ss*k//p+1)