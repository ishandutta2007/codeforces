h1,a1,c1=map(int,input().split())
h2,a2=map(int,input().split())
out=[]
while h2>0:
    if h2<=a1:
        out.append("STRIKE")
        h2-=a1
    elif h1<=a2:
        out.append("HEAL")
        h1+=c1-a2
    else:
        out.append("STRIKE")
        h1-=a2
        h2-=a1
#    print(h1,h2)
print(len(out))
for i in out:
    print(i)