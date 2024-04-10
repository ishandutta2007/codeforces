n=int(input())
n2=n**2
if n<3:
    print(-1)
elif n%2==1:
    print(n2//2,n2//2+1)
else:
    L=[]
    x=n
    i=0
    while x%2==0:
        x//=2
        i+=1
    if x!=1:
        x2=x**2
        xx=2**i
        print((x2//2)*xx,((x2//2)+1)*xx)
    else:
        print(3*n//4,5*n//4)