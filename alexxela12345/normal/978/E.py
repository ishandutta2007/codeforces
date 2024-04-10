n, w = list(map(int, input().split()))
a = list(map(int, input().split()))
cur = 0
mn, mx = 0, w
for el in a:
    cur += el
    if cur < 0:
        mn = max(mn, abs(cur))
    else:
        mx = min(mx, w - cur)
if mn > mx:
    print(0)
else:
    print(mx - mn + 1)