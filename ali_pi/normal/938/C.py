from __future__ import division
import math
t = int(raw_input())
for i in range(t):
  x = int(raw_input())
  found = False
  if x == 0:
    print "1 1"
    continue
  elif x == 1 or x == 2:
    print "-1"
    continue
  elif x == 3:
    print "2 2"
    continue
  for j in range(2,int(math.sqrt(x))+1):
    if x%j == 0:
      n = max(x//j,j)
      n2 = min(x//j,j)
      b = (n-n2)/2
      if int(b) != b or b == 0:
        continue
      b = int(b)
      temp = n-b
      b = temp//b
      if temp**2-(temp//b)**2 == x:
        found = True
        print temp,b
        break
  if not found:
    print -1