b=input()
b=b.split()
m=int(b[0])
n=int(b[1])
a=int(b[2])
x=m//a
y=n//a
if m%a!=0:
    x=x+1
if n%a!=0:
    y=y+1
print(x*y)