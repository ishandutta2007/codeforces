import sys
input = sys.stdin.readline

n, m = map(int, input().split())
a = [input() for i in range(n)]
s = input().strip()

for i in range(n):
  for j in range(m):
    if a[i][j] == 'S':
      sx, sy = i, j
    if a[i][j] == 'E':
      ex, ey = i, j

ans = 0

import itertools
for p in itertools.permutations([(-1, 0), (1, 0), (0, 1), (0, -1)], 4):
  x, y = sx, sy
  good = True
  for v in s:
    x += p[int(v)][0]
    y += p[int(v)][1]
    if not(0 <= x < n and 0 <= y < m and a[x][y] != '#'):
      good = False
    if (x, y) == (ex, ey):
      break
  if (x, y) != (ex, ey):
    good = False
  if good:
    ans += 1
  
print(ans)