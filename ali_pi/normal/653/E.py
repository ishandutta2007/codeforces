import sys
n,m,k = map(int, sys.stdin.readline().split(' '))
V = map(set, [set()]*n)
for _ in range(m):
  u,v = map(int, sys.stdin.readline().rstrip('\n').split(' '))
  u-=1
  v-=1
  V[u].add(v)
  V[v].add(u)
if n-1-len(V[0])<k:
  print ('impossible')
  exit()
  
visited = set(range(1,n))
comp = 0
for i in range(1,n):
  if i in visited:
    visited.remove(i)
    comp += 1
    if comp>k:
      print ('impossible')
      exit()
    can_connect_to_root = False
    stack = [i]
    for s in stack:
      can_connect_to_root |= s not in V[0]
      removed = set()
      for x in visited:
        if x not in V[s]:
          removed.add(x)
          stack.append(x)
      visited.difference_update(removed)
    if not can_connect_to_root:
      print ('impossible')
      exit()
print ('possible')