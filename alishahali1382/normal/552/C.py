w,m=map(int,input().split())

def f(m,w):
    while m!=0:
        x=(m+1)%w
        if x==0:
            m=(m+1)//w
        elif x<3:
            m=m//w
        else:
            return False
        
    return True
if w==2:
    print("YES")
elif f(m,w):
    print("YES")
else:
    print("NO")