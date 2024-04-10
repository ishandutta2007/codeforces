n, w  =tuple(int(i) for i in raw_input().split())
 
a = tuple(int(i) for i in raw_input().split())
 
l = 0
r = 0
cur = 0

for i in a:
    cur += i
    l = min(l,cur)
    r = max(r, cur)

ans = w - (r-l)
y = w - r
x = 0 - l
ans = y - x + 1
print max(ans, 0)