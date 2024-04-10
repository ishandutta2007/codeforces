t=input()
t=t.split()
t1=int(t[0])
t2=int(t[1])
a=input()
a=a.split()
h=int(a[0])
d=int(a[1])
c=int(a[2])
n=int(a[3])
if t1>=20:
    c=c*(8/10)
    q=h//n
    if h//n-h/n!=0:
       q=q+1
    print((q)*c)
else:
    td=(20-t1)*60-t2
    h2=h+td*d
    q2=h2//n
    q=h//n
    if h2//n-h2/n!=0:
       q2=q2+1
    if h//n-h/n!=0:
       q=q+1
    print(min((q2)*c*(8/10),(q)*c))