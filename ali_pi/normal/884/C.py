def dfs(u):
 res = 0
 while p[u] != 0:
  res += 1
  p[u], u = 0, p[u]
 return res
R=lambda:list(map(int,raw_input().split()))
n = R()
p = [0] + R()
val = sorted([dfs(u) for u in p])
print(sum(list(map(lambda x: x*x, val))) + 2 * val[-1] * val[-2])