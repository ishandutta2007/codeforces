from sys import*
from itertools import*
def main():
    n = int(raw_input())
    p = map(int, raw_input().split(), repeat(10, n - 1))
    ch = [[] for _ in xrange(n)]
    for i, x in enumerate(p, 1):
        ch[x-1].append(i)
    st = []
    pu = st.append
    po = st.pop
    col = [None] * n
    L = [0] * n
    R = [0] * n
    c = 0
    pu(0)
    while st:
        x = po()
        if col[x] is None:
            L[x] = c
            c += 1
            pu(x)
            col[x] = 1
            for y in ch[x]:
                pu(y)
        else:
            col[x] = 0
            R[x] = c
    N = 1 << 18
    b = [0] * (N + N)
    lz = [0] * (N + N)
    t = raw_input().split()
    for i, x in enumerate(t):
        if x == '1':
            b[L[i]+N] += 1
    for i in xrange(N - 1, 0, -1):
        b[i] = b[i+i] + b[i+i+1]
    ans = []
    def inv(b, lz, v, lh):
        b[v] = lh - b[v]
        lz[v] ^= 1
    def push(b, lz, o, ln):
        for i in xrange(18, 0, -1):
            j = o >> i
            if lz[j]:
                inv(b, lz, j+j, ln)
                inv(b, lz, j+j+1, ln)
                lz[j] = 0
            ln /= 2
    q = int(raw_input())
    for _ in xrange(q):
        ln, x = raw_input().split()
        x = int(x, 10) - 1
        l, r = L[x] + N, R[x] + N - 1
        push(b, lz, l, N / 2)
        push(b, lz, r, N / 2)
        if ln[0] == 'g':
            l, r = L[x] + N, R[x] + N
            tmp = 0
            while l < r:
                if l & 1:
                    tmp += b[l]
                    l += 1
                if r & 1:
                    r -= 1
                    tmp += b[r]
                l /= 2
                r /= 2
            ans.append(tmp)
        else:
            l, r = L[x] + N, R[x] + N
            n = 1
            while l < r:
                if l & 1:
                    inv(b, lz, l, n)
                    l += 1
                if r & 1:
                    r -= 1
                    inv(b, lz, r, n)
                l /= 2
                r /= 2
                n += n
            l, r = L[x] + N, R[x] + N - 1
            n = 1
            while l > 1:
                l /= 2
                r /= 2
                n += n
                b[l] = b[l+l] + b[l+l+1]
                if lz[l]: b[l] = n - b[l]
                b[r] = b[r+r] + b[r+r+1]
                if lz[r]: b[r] = n - b[r]
    print('\n'.join(map(str, ans)))
main()