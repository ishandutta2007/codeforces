import sys
input = sys.stdin.readline

n, r = map(int, input().split())
xs = list(map(int, input().split()))

points = []

for x in xs:
  y = r
  for x0, y0 in points:
    if abs(x - x0) <= 2 * r:
      y = max(y, y0 + ((2*r)**2 - (x-x0)**2)**0.5)
  points.append((x, y))

print(" ".join("%.20f" % p[1] for p in points))