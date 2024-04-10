#!/usr/bin/env python

n, a, b = [int(x) for x in input().split()]

if a * b < n:
  print(-1)
else:
  odd = iter(range(1, n + 1, 2))
  even = iter(range(2, n + 1, 2))
  for i in range(a):
    for j in range(b):
      if (i + j) % 2 == 0:
        print(next(odd, 0), end=' ')
      else:
        print(next(even, 0), end=' ')
    print()