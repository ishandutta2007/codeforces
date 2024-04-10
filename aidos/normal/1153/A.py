n, t = map(int, input().split())
a = []
for i in range(n):
    s, d = map(int, input().split())
    cur = 0
    if s >= t:
        cur = s
    else:
        x = (t-s + d-1)//d
        cur = s + d * x
    a.append(cur)
print(a.index(min(a)) + 1)