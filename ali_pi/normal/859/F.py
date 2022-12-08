from sys import*
from itertools import*
from collections import*
def main():
    n, c = map(int, stdin.readline().split())
    s = map(int, stdin.readline().split(), repeat(10, 2 * n - 1))
    l = len(s)
    st = min(c, s[0])
    ss = s[0]
    ans = st
    q = deque([(s[0], st)])
    for i in xrange(2, l, 2):
        q.append(s[i-1])
        ss += s[i] + s[i-1]
        while len(q) > 2:
            z = q[-1]
            x, y = q[-2]
            if x + z - y <= 0:
                q.pop()
                q.pop()
                q[-2] = (q[-2][0] + x + z, q[-2][1] + y)
            else:
                break
        bt = min(ss, c) - st
        while ss > c and q:
            x, y = q.popleft()
            ss -= x
            st -= y
            x = q.popleft()
            ss -= x
        z = min(ss, c) - st
        if bt < z:
            bt = z
        if bt < 0:
            bt = 0
        st += bt
        q.append((s[i], bt))
        ans += bt
    print(ans)
main()