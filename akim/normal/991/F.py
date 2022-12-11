# a ^ b * c ^ d + e ^ f
# a ^ b * c ^ d + g

sh = {}
for i in range(1, 100):
    for j in range(1, 100):
        if i ** j > 10 ** 10:
            break
        k = i ** j
        v = str(i) + '^' + str(j)
        if len(str(k)) < len(v):
            v = str(k)
        if k not in sh or len(sh[k]) > len(v):
            sh[k] = v

n = int(input())
ans = str(n)
for a in range(1, 100000):
    for b in range(1, 30):
        if a ** b > n or a == 1 and b > 1:
            break
        for c in range(1, 10):
            for d in range(1, 30):
                if a > 300 and d > 1:
                    break
                if (a ** b) * (c ** d) > n or c == 1 and d > 1:
                    break
                g = n - (a ** b) * (c ** d)

                sa = str(a) if b == 1 else str(a) + '^' + str(b)
                sc = str(c) if d == 1 else str(c) + '^' + str(d)
                x = sa
                x = x if c ** d == 1 else x + '*' + sc
                y = x if g == 0 else x + '+' + str(g)
                if g != 0 and g in sh:
                    y = x + '+' + sh[g]
                if len(y) < len(ans):
                    ans = y
        if a > 300:
            continue
        for e in range(0, 10):
            for f in range(1, 30):
                if (a ** b) + (e ** f) > n or e == 1 and f > 1:
                    break
                if e == 0 and f > 1:
                    break
                if (n - (e ** f)) % (a ** b) != 0:
                    continue
                g = (n - (e ** f)) // (a ** b)
                sa = str(a) if b == 1 else str(a) + '^' + str(b)
                sc = str(g)
                x = sa
                x = x if g == 1 else x + '*' + sc
                y = x if e == 0 else x + '+' + sh[e ** f]
                if len(y) < len(ans):
                    ans = y

print(ans)