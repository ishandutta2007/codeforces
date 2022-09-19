n,m = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
t=0
while(len(a) > 0 and len(b)>0):
    if(a[0] <= b[0]):
        a.pop(0)
        b.pop(0)
        t+=1
    else:
        a.pop(0)
print(t)