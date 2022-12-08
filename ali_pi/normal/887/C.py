a=list(map(int,raw_input().split()))
x,i=0,0
w=[]
while i<24:
    n=len(set(a[i:i+4]))
    if n==1:x+=1
    elif n==2:w.append(set(a[i:i+4]))
    i+=4
w=set(frozenset(i) for i in w)
print(['NO','YES'][ x==2 and len(set(w))==4])