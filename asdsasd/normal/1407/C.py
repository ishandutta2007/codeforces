import sys
input = sys.stdin.buffer.readline
from math import gcd

#p = [4, 1, 5, 3, 2]

def main():
    n = int(input())
    ans = [-1 for _ in range(n)]
    pos = 0
    now = 1
    cnt = 1
    for _ in range(n - 1):
        print("?", pos + 1, now + 1)
        sys.stdout.flush()
        #p1 = p[pos] % p[now]
        p1 = int(input())
        print("?", now + 1, pos + 1)
        sys.stdout.flush()
        #p2 = p[now] % p[pos]
        p2 = int(input())
        if p1 > p2:
            ans[pos] = p1
            pos = now
            now = cnt + 1
        else:
            ans[now] = p2
            now = cnt + 1
        cnt += 1
    ans[pos] = n
    print("!", *ans)
        
"""
for _ in range(int(input())):
    main()
"""
main()