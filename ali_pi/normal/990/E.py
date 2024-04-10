import sys
from math import ceil

n, m, k = map(int, sys.stdin.readline().split())
places = [True for _ in range(n)]
for x in map(int, sys.stdin.readline().split()):
    places[x] = False
costs = list(map(int, sys.stdin.readline().split()))
if not places[0]:
    print(-1)
    sys.exit(0)

prev = [i for i in range(n)]
last = 0
for i in range(n):
    if places[i]:
        last = i
    prev[i] = last

best_cost = float('inf')
for lamp in range(k, 0, -1):
    min_cost = ceil(n/lamp) * costs[lamp-1]
    if min_cost >= best_cost:
        continue

    # try this shit
    cost = costs[lamp-1]
    reach = lamp
    fail = False

    while reach < n:
        if prev[reach] + lamp <= reach:
            fail = True
            break
        reach = prev[reach] + lamp
        cost += costs[lamp - 1]

        if cost + (ceil((n - reach)/lamp) * costs[lamp-1]) >= best_cost:
            fail = True
            break

    if not fail:
        best_cost = min(best_cost, cost)

print(best_cost if best_cost != float('inf') else -1)