n,t=map(int,input().split())
L=list(map(int,input().split()))+[0]

flag=False
x=0
while x<t:
    if x+1==t:
        flag=True
        break
    x+=L[x]
if flag:
    print("YES")
else:
    print("NO")