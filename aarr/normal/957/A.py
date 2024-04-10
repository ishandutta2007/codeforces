n=int(input())
a=input()
def check(n,a):
    for i in range(n-1):
        if a[i]==a[i+1] and a[i]!='?':
            return False
    return True
l=[]
c=0
for i in range(n):
    if a[i]=='?':
        c=c+1
    l.append(a[i])
k=0
for i in range(n-2):
    if a[i+1]=='?' and a[i]==a[i+2]:
        k=1
if check(n,l)==False:
    print('No')
    k=2
def main(l,n):
    t=[]
    for i in l:
        b=i.index('?')
        q=[]
        r=[]
        s=[]
        for j in range(b):
            q.append(i[j])
            r.append(i[j])
            s.append(i[j])
        q.append('Y')
        r.append('C')
        s.append('M')
        if 1==1:
            for j in range(b+1,n):
                q.append(i[j])
                r.append(i[j])
                s.append(i[j])
        if check(n,q)==True:
            t.append(q)
        if check(n,r)==True:
            t.append(r)
        if check(n,s)==True:
            t.append(s)
    return t
if k==1:
    print('Yes')
if k==0:
    l=[l]
    for i in range(c):
        l=main(l,n)
    d=0
    for i in l:
        if check(n,i)==True:
            if d==1:
                print('Yes')
            d=d+1
    if d==0 or d==1:
        print('No')