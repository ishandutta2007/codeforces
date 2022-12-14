import sys

m, n = map(int, input().split())

def query(x):
  print(x)
  sys.stdout.flush()
  ret = int(input())
  if ret in [0, -2]:
    exit(0)
  return ret

p = [query(1) == -1 for _ in range(n)]

low, high = 0, m+1
for i in p * 100:
  mid = (low + high) >> 1
  ret = query(mid)
  if not i:
    ret = -ret
  if ret == -1:
    low = mid
  else:
    high = mid