n,m  =tuple(int(i) for i in raw_input().split())

s = []
d = []
c = []
for i in range(m):
  x,y,z = tuple(int(i) for i in raw_input().split())
  s.append(x)
  d.append(y)
  c.append(z)

e = zip(range(1,m+1), s, d, c)
e = sorted(e, key=lambda x: x[2])

ans = [0] * n

for i in range(m):
    ans[d[i]-1] = m+1

fail = False
for x in e:
    idx, s, d, c = x
    s -= 1
    d -= 1
    for i in range(n):
        if c == 0:
            break
        if i >= s and ans[i] == 0:
            ans[i] = idx
            c-=1
        if i >= d:
            fail = True
            break
        
if fail:
    print -1
else:
    print ' '.join(str(i) for i in ans)