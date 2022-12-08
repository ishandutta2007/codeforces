from math import*
n = input()
p = [bin(p)[2:] for p in range(0,512)]
def mset(s):
    ss = set()
    for k in range(0,10):
        for pi in range(0,2 ** k):
            cs = p[pi]
            cs = (k - len(cs)) * "0" + cs
            if cs in s:
                ss.add(cs)
    return ss
def q(s):
    for k in range(0,10):
        for pi in range(0,2 ** k):
            cs = p[pi]
            cs = (k - len(cs)) * "0" + cs
            if not cs in s:
                return k - 1
s = [[v[:9], v[-9:], mset(v)] for v in [raw_input() for i in range(n)]]
for qa, qb in [[int(v) - 1 for v in raw_input().split()] for i in range(input())]:
    v = [s[qa][0], s[qb][1], mset(s[qa][1] + s[qb][0]) | s[qa][2] | s[qb][2]]
    if len(v[0]) < 9:
        v[0] = (v[0] + s[qb][0])[:9]
    if len(v[1]) < 9:
        v[1] = (s[qa][1] + s[qb][1])[-9:]
    s += [v]
    print(max(q(v[2]),0))