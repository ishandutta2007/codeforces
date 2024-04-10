t,s,x=map(int,input().split())
if ((x-t)%s in (0,1) and t+s<=x or t==x) and x!=t+1:
    print("YES")
else:
    print("NO")