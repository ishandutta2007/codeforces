a=int(input())
ans=0
if (a==1 or a==2):
    print(-1)
    ans=1
if (a%2==1):
    b=a*a//2;
    c=b+1;
    if (ans==0):
        print(str(b)+' '+str(c))
    elif (ans==0):
        print(-1)
        print('!')
    ans=1
if (a&(a-1)==0):
    b=3*a//4
    c=5*a//4
    if (ans==0):
        print(str(b)+' '+str(c))
    elif (ans==0):
        print(-1)
    ans=1
cnt=0
while (a%2==0):
    cnt+=1
    a//=2
b=(pow(a,2)//2)*pow(2,cnt)
c=(pow(a,2)//2+1)*pow(2,cnt)
if (ans==0):
    print(str(b)+' '+str(c))
elif (ans==0):
    print(-1)