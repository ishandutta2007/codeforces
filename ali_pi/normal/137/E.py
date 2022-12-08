s=[(0,0)]
c=0
for i,x in enumerate(raw_input()):
  c+=-1 if x.lower() in 'aeiou' else 2
  s.append((c,i+1))
u,v,w=10**9,0,0
for x in sorted(s):
  if u<x[1]:
    if x[1]-u>v:
      v,w=x[1]-u,1
    elif x[1]-u==v:
      w+=1
  u=min(u,x[1])
if v>0:
  print v,w
else:
  print('No solution')