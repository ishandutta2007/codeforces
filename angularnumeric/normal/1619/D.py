import sys
from math import gcd
from itertools import groupby

# sys.setrecursionlimit(10**6)

rt = lambda: map(int, input().split())
ri = lambda: int(input())
rl = lambda: list(map(int, input().split()))


def main():
    t = ri()
    for _ in range(t):
        input()
        m, n = rt()
        lo, hi = 1, 10**9
        ar = []
        for _ in range(m):
            ar.append(rl())

        while lo < hi:
            mid = lo + (hi-lo+1)//2
            #print (lo, hi, mid)
            f = 1
            cnt = 0
            s = set()
            for i in range(n):
                g = 0
                for j in range(m):
                    if ar[j][i] >= mid:
                        g = 1
                        cnt += 1
                        s.add(j)
                if g == 0:
                    f = 0
                    break

            if f == 0:
                hi = mid-1
            else:
                if cnt > len(s):
                    lo = mid
                else:
                    hi = mid-1

        print (lo)


if __name__ == '__main__':
    main()