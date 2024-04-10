import sys
input = sys.stdin.buffer.readline
from math import gcd

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    alst.sort(reverse = True)
    used = [False for _ in range(n)]
    ans = [alst[0]]
    used[0] = True
    num = alst[0]
    for _ in range(n - 1):
        pos = 0
        tt = 0
        for i, a in enumerate(alst):
            if used[i]:
                continue
            g = gcd(num, a)
            if g > tt:
                tt = g
                pos = i
        ans.append(alst[pos])
        used[pos] = True
        num = tt
    print(*ans)
        

for _ in range(int(input())):
    main()