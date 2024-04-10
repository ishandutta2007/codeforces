def frog(x):
  la, lb, lc=a, b, c
  add=0
  while True:
    if use[x]==0:
      la-=1
    elif use[x]==1:
      lb-=1
    else:
      lc-=1
    if min(la, lb, lc)<0:
      return add
    add+=1
    x=(x+1)%7

a, b, c=map(int, input().split())
full=1000000000
full=min(full, a//3)
full=min(full, b//2)
full=min(full, c//2)
a-=full*3
b-=full*2
c-=full*2


use=[0, 1, 2, 0, 2, 1, 0]
ans=[]
for i in range(7):
  ans.append(frog(i))
  
print(7*full+max(ans))