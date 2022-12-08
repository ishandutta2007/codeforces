from sys import*
from random import*
def main():
    n = int(stdin.readline())
    e = set()
    r = set()
    for line in stdin:
        s, l = line.split()
        if l == '1':
            e.add(s)
        else:
            r.add(s)
    en = len(e)
    es = set(map(str, xrange(1, en + 1)))
    rs = set(map(str, xrange(en + 1, n + 1)))
    al = es | rs
    rtoe, etor, eo, ro, ee, rr = [set() for _ in '012345']
    for x in es:
        if x in r:
            etor.add(x)
        elif x in e:
            ee.add(x)
        else:
            eo.add(x)
    for x in rs:
        if x in e:
            rtoe.add(x)
        elif x in r:
            rr.add(x)
        else:
            ro.add(x)
    es -= ee
    rs -= rr
    e -= al
    r -= al
    ans = []
    if not eo and not ro:
        if not rtoe:
            print 0
            return
        x = rtoe.pop()
        y = 'a'
        ans.append((x, y))
        e.add(y)
        ro.add(x)
    while rtoe or etor or r or e:
        if rtoe and eo:
            x = rtoe.pop()
            ans.append((x, eo.pop()))
            ro.add(x)
            continue
        if etor and ro:
            x = etor.pop()
            ans.append((x, ro.pop()))
            eo.add(x)
            continue
        if r:
            ans.append((r.pop(), ro.pop()))
            continue
        if e:
            ans.append((e.pop(), eo.pop()))
    print len(ans)
    for x, y in ans:
        print "move", x, y
main()