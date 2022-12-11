import sys
sys.setrecursionlimit(1000000)
n = int(raw_input())
paths = [[] for x in range(n)]
for i in range(n-1):
  a,b = map(int,raw_input().split())
  a -= 1
  b -= 1
  paths[a].append(b)
  paths[b].append(a)
vals = list(map(int,raw_input().split()))

def dfs(cur,par,val):
  for i in paths[cur]:
    if i==par:
      continue
    if val==-1:
      if dfs(i,cur,vals[i]):
        return 1
    else:
      if vals[i] != val:
        return 1
      if dfs(i,cur,val):
        return 1
  return 0

for i in range(n):
  for j in paths[i]:
    if vals[i] != vals[j]:
      if not dfs(i,-1,-1):
        print "YES"
        print i+1
      elif not dfs(j,-1,-1):
        print "YES"
        print j+1
      else:
        print "NO"
      sys.exit()
print "YES"
print 1