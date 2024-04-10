import sys
input = sys.stdin.readline
from heapq import *
def ask(lst):
    print("?", *lst, flush=True)
    return int(input())

def main():
    n, k = map(int, input().split())
    
    i = 0
    while 1:
        if i > 10 ** 6:
            print(-1)
            return
        i += 1
        if i % 2 == 1:
            max_ = i
        else:
            max_ = i - 1
        if k * i < n or (k * i - n) % 2 == 1 or n * max_ < i * k:
            continue
        else:
            break
    cnt = [1] * n
    z = k * i - n
    if i % 2 == 1:
        max_ = i
    else:
        max_ = i - 1
    
    for i in range(n):
        plus = min(z, max_ - 1)
        cnt[i] += plus
        z -= plus
    hq = []
    for i, c in enumerate(cnt, 1):
        heappush(hq, (-c, i))
    ans = 0
    while hq:
        q = []
        add = []
        for _ in range(k):
            c, i = heappop(hq)
            c += 1
            q.append(i)
            if c != 0:
                add.append((c, i))
        ans ^= ask(q)
        for tmp in add:
            heappush(hq, tmp)
    print("!", ans)
            
    
    
for _ in range(1):
    main()