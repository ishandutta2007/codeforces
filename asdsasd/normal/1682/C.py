import sys
input = sys.stdin.readline

def solve(A):
    A.sort()
    cnt = {}
    for a in A:
        cnt[a] = cnt.get(a, 0) + 1
    c = 0
    ans = 0
    for k, v in cnt.items():
        if v == 1:
            c += 1
        else:
            ans += 1
    ma = max(A)
    return ans + (c + 1) // 2
    
    
for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    print(solve(A))

exit()

import itertools
from bisect import bisect_left

def lis(A):
    lst = []
    for a in A:
        p = bisect_left(lst, a)
        if len(lst) == p:
            lst.append(a)
        else:
            lst[p] = a
    return len(lst)


def stupid(A):
    A = A[:]
    ret = 0
    for P in itertools.permutations(A):
        ret = max(ret, min(lis(P), lis(P[::-1])))
    return ret

import random
random.seed(0)
for _ in range(1000):
    n = 8
    A = random.choices(range(10), k=n)
    assert solve(A) == stupid(A), (solve(A), stupid(A), A)