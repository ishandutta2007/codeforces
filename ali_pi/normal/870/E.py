n = int(raw_input())
disjointSet = [-1] * n
def root(x, level=200):
    dp = []
    while disjointSet[x] >= 0:
        dp.append(x)
        x = disjointSet[x]
    for i in dp:
        disjointSet[i] = x
    return x

def join(x, y):
    r1, r2 = root(x), root(y)
    if r1 == r2:
        return
    disjointSet[r2] = r1

points = []
vertPoints = {}
horizPoints = {}
for i in range(n):
    a, b = map(int,raw_input().split())
    points.append((a, b))
    if a in vertPoints:
        join(i, vertPoints[a])
    else:
        vertPoints[a] = i
    if b in horizPoints:
        join(i, horizPoints[b])
    else:
        horizPoints[b] = i
        
sets = {}
for i in range(n):
    r = root(i)
    if r in sets:
        sets[r].append(points[i])
    else:
        sets[r] = [points[i]]

ans = 1
for i in sets:
    s = sets[i]
    horiz = [x for x,y in s]
    vert = [y for x,y in s]
    tmp = len(set(horiz)) + len(set(vert))
    if tmp <= len(s):
        ans *= 2 ** tmp
    else:
        ans *= 2 ** tmp - 1
    ans %= 10 ** 9 + 7

print(ans % (10 ** 9 + 7))