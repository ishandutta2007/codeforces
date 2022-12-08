n=input()
def f(k):
 s=(n+1)//2;m=n
 while s>0and m:
  l=min(k,m);s-=l;m-=l;m-=m//10
 return s<=0
l=[0,n]
while l[1]-l[0]>1:
 m=sum(l)//2;l[f(m)]=m
print(l[1])