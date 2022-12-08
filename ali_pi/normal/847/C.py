ch=raw_input()
l=ch.split(' ')
n=int(l[0])
k=int(l[1])
l1='('
l2=')'
l3='()'
s=0
mi=0
ch=''
from math import sqrt
q=int(sqrt(2*k))
while k>=(q*(q-1))/2:
    q=q+1
q=q-1
d=int(k-(q*(q-1))/2)
mi=q
i=0
if d!=0:
    mi=q+1
    i=1
if n<mi:
    print('Impossible')
else:
    c=n-mi
    print(c*l3+d*l1+i*l3+(q-d)*l1+q*l2)