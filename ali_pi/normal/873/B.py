raw_input()
d={0:-1}
a=b=0
for i,c in enumerate(raw_input()):
    b+=2*int(c)-1
    d[b]=x=d.get(b,i)
    a=max(a,i-x)
print(a)