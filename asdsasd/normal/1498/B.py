import sys
input = sys.stdin.readline
from collections import defaultdict

def main():
    n, W = map(int, input().split())
    wlst = list(map(int, input().split()))
    dd = defaultdict(int)
    le = W.bit_length()
    cnt = [0] * le
    for w in wlst:
        cnt[w.bit_length() - 1] += 1

    
    def ok(x):
        tmp = 0
        for i in range(le - 1, -1, -1):
            if W >> i & 1:
                tmp += x
            tmp -= cnt[i]
            if tmp < 0:
                return False
            tmp *= 2
        return True
    
    l = 0
    r = n
    while r - l > 1:
        mid = (r + l) // 2
        if ok(mid):
            r = mid
        else:
            l = mid
    print(r)
    
    
    
for _ in range(int(input())):
    main()