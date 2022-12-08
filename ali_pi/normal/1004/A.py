R=lambda:map(int,input().split())
n,d=R()
r=2
a=R()
p=next(a)
for x in a:
 r+=(x-p>=d*2)+(x-p>d*2);p=x
print(r)