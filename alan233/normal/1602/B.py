from collections import*
R=lambda:map(int,input().split())
t,=R()
while t:
 t-=1;R();a=[*R()],;q,=R()
 for _ in[0]*11:c=Counter(b:=a[-1]);a+=[c[x]for x in b],
 while q:q-=1;x,k=R();print(a[min(k,10)][x-1])