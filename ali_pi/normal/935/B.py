raw_input()
s=raw_input()
a=p=0
x=[0,0]
for c in s:
 a+=x[0]==x[1]and c==p;x[c<'U']+=1;p=c
print(a)