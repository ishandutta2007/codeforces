from collections import Counter
n = int(raw_input())
s = raw_input()
C = Counter()
for c in s:
    C[c] += 1

odd = 0
for c, v in C.items():
    if v%2 == 1: odd += 1

l = -1
if odd == 0:
    s = ''
    for c, v in C.items():
        s += c*(v//2)
    print(1)
    print(s + s[::-1])
else:
    for ll in range(n, 0, -1):
        if n%ll != 0: continue
        if n//ll >= odd and ll%2 == 1:
            l = ll
            break
    nbr = n//l
    out = []
    C = list(map(tuple, C.items()))
    for i in range(nbr):
        for i, (c, v) in enumerate(C):
            if v%2 == 1:
                break
        if v == 0:
            i, c, v = next((a, b, c) for a, (b, c) in enumerate(C) if c != 0)

        C[i] = (c, v - 1)
        m = c
        s = []
        left = l//2
        for i, (c, v) in enumerate(C):
            sub = min(v//2,left)
            s += [c]*sub
            C[i] = (c, v - sub*2)
            left -=sub
        ss = ''.join(s)
        out.append(ss + m + ss[::-1])
    print(len(out))
    print(' '.join(out))