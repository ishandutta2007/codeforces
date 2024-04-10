def same(d):
    s=set()
    for i in d.keys():
        s.add(d[i])
    if len(s)==1:
        return True
    else:
        return False
n=input()
d={}
for i in range(n):
    t=input()
    if t in d.keys():
        d[t]+=1 
    else:
        d[t]=1
if len(d)==2 and same(d):
    print("YES")
    for i in d.keys():
        print i;end=" "
else:
    print("NO")