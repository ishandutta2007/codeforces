from sys import*
from itertools import*
def main():
    n = int(stdin.readline())
    dat = stdin.read().split()
    v = map(int, dat[::2], repeat(10, n))
    st = None
    for i in xrange(n):
        if dat[i*2+1] == 'P':
            st = i
            break
    x = y = z = None
    ans = 0
    if st is None:
        for i, p in enumerate(v):
            if dat[i*2+1] == 'B':
                if x is None:
                    ans -= p
                x = p
            else:
                if y is None:
                    ans -= p
                y = p
        if x is not None:
            ans += x
        if y is not None:
            ans += y
        print ans
        return
    mb = mc = 0
    for i in xrange(st, n):
        p = v[i]
        if dat[i*2+1] == 'P':
            if x is not None:
                if mb < p - y:
                    mb = p - y
                if mc < p - z:
                    mc = p - z
                k = 2 * (p - x) - mb - mc
                if k > p - x:
                    k = p - x
                ans += p - x + k
            mb = mc = 0
            x = y = z = p
        elif dat[i*2+1] == 'B':
            if mb < p - y:
                mb = p - y
            y = p
        else:
            if mc < p - z:
                mc = p - z
            z = p
    if y is not None and y > x:
        ans += y - x
    if z is not None and z > x:
        ans += z - x
    for i in xrange(st):
        if dat[i*2+1] == 'B':
            ans += v[st] - v[i]
            break
    for i in xrange(st):
        if dat[i*2+1] == 'R':
            ans += v[st] - v[i]
            break
    print ans
main()