import sys
input = sys.stdin.readline
ans = 0

for x in input():
  if x in "aeiou13579":
    ans += 1
  
print(ans)