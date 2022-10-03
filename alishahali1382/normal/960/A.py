s=input()
L=[0,0,0]
ss=s.lstrip("a")
L[0]=len(s)-len(ss)
sss=ss.lstrip("b")
L[1]=len(ss)-len(sss)
ssss=sss.lstrip("c")
L[2]=len(sss)-len(ssss)
if ssss!="":
    print("NO")
elif 0 in L:
    print("NO")
else:
    if L[2] in (L[0],L[1]):
        print("YES")
    else:
        print("NO")