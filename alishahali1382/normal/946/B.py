a,b=map(int,input().split())
while True:
    f=True
    if b==0:
        break
    if a>=2*b:
        a=a%(2*b)
        f=False
    if a==0:
        break
    if b>=2*a:
        b=b%(2*a)
        f=False
    if f:
        break
print(a,b)