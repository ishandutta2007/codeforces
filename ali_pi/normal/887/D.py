from sys import stdin
from collections import deque
def main():
    n, a, b, c, d, st, l = map(int, input().split())
    q = deque()
    po = q.popleft
    pu = q.append
    mq = deque()
    mpop = mq.pop
    mpo = mq.popleft
    mpu = mq.append
    sb = [0] * (n + 1)
    mst = st
    pu((0, 0, mst, st))
    pp = 0
    for i, line in enumerate(stdin):
        line = line.split()
        t = int(line[0], 10)
        while q and q[0][0] + l <= t:
            p, j, ma, sa = po()
            if ma < 0:
                print (-1)
                return
            while mq and mq[0][1] < p:
                mpo()
            sa += (-sb[j] + mq[0][0]) if mq else 0
            if ma > sa:
                ma = sa
            if ma >= 0:
                print (min(pp, p))
                return
            pp = p + 1
        pu((t, i, mst, st))
        if line[1] == '1':
            st += a
            x = sb[i] + c
        else:
            st -= b
            x = sb[i] - d
        if mst > st:
            mst = st
        while mq and mq[-1][0] > x:
            mpop()
        mpu((x, t))
        sb[i+1] = x
    pu((t + 1, n, mst, st))
    while q:
        p, j, ma, sa = po()
        if ma < 0:
            print (-1)
            return
        while mq and mq[0][1] < p:
            mpo()
        sa += (-sb[j] + mq[0][0]) if mq else 0
        if ma > sa:
            ma = sa
        if ma >= 0:
            print (min(pp, p))
            return
        pp = p + 1
    print (-1)
main()