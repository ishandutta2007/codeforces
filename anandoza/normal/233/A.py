n = int(raw_input())
if n % 2 == 0:
  print " ".join(map(str, reversed(range(1, n+1))))
else:
  print -1