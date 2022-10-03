n,k=map(int,input().split())
if k>2*n-1:
    print(0)
elif k%2==0:
    first=max(k-n, 1)
    last=min(n, k-first)
    dif=(last-first+1)
    if dif%2==0:
        print(dif//2-1)
    else:
        print(dif//2)
else:
    first=max(k-n, 1)
    last=min(n, k-first)
    dif=(last-first+1)
    print(dif//2)