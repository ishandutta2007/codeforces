n, m  = (int(x) for x in raw_input().strip().split())
coproc = [int(x) for x in raw_input().strip().split()]
edges = []
for _ in range(m):
  edges.append((int(x) for x in raw_input().strip().split()))
inorder = [0] * n 
adj = [[] for _ in range(n)]
for u, v in edges:
  adj[v].append(u)
  inorder[u] += 1
queue0 = [u for u in range(n) if inorder[u]==0 and not coproc[u]]
queue1 = [u for u in range(n) if inorder[u]==0 and coproc[u]]
res = 0 
while len(queue0)>0 or len(queue1)>0:
  
  while queue0:
    next0 = []
    for u in queue0:
      for v in adj[u]:
        inorder[v] -= 1 
        if inorder[v] == 0:
          if coproc[v]:
            queue1.append(v)
          else:
            next0.append(v)
    queue0 = next0
    
  if queue1:
    res += 1   
  while queue1:
    next1 = []
    for u in queue1:
      for v in adj[u]:
        inorder[v] -= 1 
        if inorder[v] == 0:
          if coproc[v]:
            next1.append(v)
          else:
            queue0.append(v)
    queue1 = next1
print(res)