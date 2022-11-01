n=int(input())
a=input()
a=a.split()
x=1
for i in range(1,n):
    if a[i]!=a[i-1]:
        break
    else:
        x=x+1
if n%x!=0:
    print('NO')
else:
    q=0
    for i in range(0,n,x):
        for j in range(x-1):
            if a[i+j]!=a[i+j+1]:
                q=1
        if i+x<n:
            if a[i]==a[i+x]:
                q=1
    if q==0:
        print('YES')
    else:
        print('NO')