import sys
input = sys.stdin.readline
from collections import defaultdict

def main():
    n = int(input())
    Slst = [input().strip() for _ in range(n)]
    ans = 0
    for i in range(5):
        lst = []
        for S in Slst:
            cnt = [0, 0]
            for s in S:
                if ord(s) - 97 == i:
                    cnt[0] += 1
                else:
                    cnt[1] += 1
            lst.append(cnt.copy())
        lst.sort(key = lambda x: x[1] - x[0])
        tmp = 0
        tota = 0
        totb = 0
        for a, b in lst:
            tota += a
            totb += b
            if tota > totb:
                tmp += 1
            else:
                break
        ans = max(ans, tmp)
    print(ans)
            
            
    
for _ in range(int(input())):
    main()