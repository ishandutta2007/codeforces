from collections import defaultdict

m = int(raw_input())
edge = defaultdict(int)
for i in range(m):
  x, y = tuple(int(i)-1 for i in raw_input().split(" "))
  edge[(x,y)] = 1
  edge[(y,x)] = 1

answer = "FAIL"
for a in range(5):
  for b in range(a+1, 5):
    for c in range(b+1, 5):
      score = edge[(a,b)] + edge[(b,c)] + edge[(c,a)]
      if score == 0 or score == 3:
        answer = "WIN"

print answer