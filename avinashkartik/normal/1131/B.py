n=int(input())
old=[0,0]
c=0
new=list(map(int,input().split()))
c+=min(new)-max(old)+1
old=new
for i in range(n-1):
  new=list(map(int,input().split()))
  if(old != new):
    if(min(new)>=max(old)):
      c+=min(new)-max(old)+1
      if(old[0]==old[1]):
        c-=1
  old=new
print(c)