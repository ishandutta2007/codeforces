from sys import*
from itertools import*
def solve(a):
    inf = 1001001001
    C = 400010
    lmn = [inf] * 400010
    lmx = [-inf] * 400010
    for x, y in a:
        x = (x - 1) / 2 + 100005
        if lmn[x] > y:
            lmn[x] = y
        if lmx[x] < y:
            lmx[x] = y
    rmn = lmn[:]
    rmx = lmx[:]
    for i in xrange(200009):
        if lmn[i+1] > lmn[i]:
            lmn[i+1] = lmn[i]
    for i in xrange(200009):
        if lmx[i+1] < lmx[i]:
            lmx[i+1] = lmx[i]
    for i in xrange(200009, 0, -1):
        if rmn[i-1] > rmn[i]:
            rmn[i-1] = rmn[i]
    for i in xrange(200009, 0, -1):
        if rmx[i-1] < rmx[i]:
            rmx[i-1] = rmx[i]
    for i in xrange(200010):
        if lmn[i] < rmn[i]:
            lmn[i] = rmn[i]
    for i in xrange(200010):
        if lmx[i] > rmx[i]:
            lmx[i] = rmx[i]
    ans = 0
    for i in xrange(200009):
        if lmn[i] < lmn[i+1]:
            lmn[i] = lmn[i+1]
    for i in xrange(200009):
        if lmx[i] > lmx[i+1]:
            lmx[i] = lmx[i+1]
    for i in xrange(200009):
        if lmn[i] < lmx[i]:
            ans += (lmx[i] - lmn[i]) / 2
    return ans
    
def main():
    n = int(stdin.readline())
    dat = map(int, stdin.read().split(), repeat(10, 2 * n))
    s = [[], []]
    for i in xrange(n):
        x, y = dat[i*2:i*2+2]
        s[(x+y)&1].append((-x+y, x+y))
    print(solve(s[0]) + solve(s[1]))
main()