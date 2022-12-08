from sys import stdin
from itertools import repeat
from heapq import heappush, heappushpop
def main():
    n = int(stdin.readline())
    a = map(int, stdin.readline().split(), repeat(10, n))
    q = []
    ans = 0
    for x in a:
        if q and x - q[0] > 0:
            ans += x - q[0]
            heappushpop(q, x)
            heappush(q, x)
        else:
            heappush(q, x)
    print ans
main()