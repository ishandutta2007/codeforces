import sys
input = sys.stdin.readline
"""
from pprint import pprint
x = ""
A = [2, 5, 1, 4, 3, 6]
def print(Q, flush):
    pprint(Q)
    B = list(map(int, Q[1:].split()))
    global x
    C = [a + b for a, b in zip(A, B)]
    se = set()
    for c in C:
        if c in se:
            break
        se.add(c)
    else:
        x = 0
        return
    for i, z in enumerate(C):
        if z == c:
            x = i + 1
            return
    
def input():
    return x
"""    
def judge(Q):
    print(Q, flush = True)
    return int(input())



def main():
    #n = 6
    n = int(input())
    for i in range(2, n + 1):
        p = judge(f"? {' '.join((map(str, [1] * (n - 1) + [i])))}")
        if p == 0:
            break
    else:
        i += 1
    ans = [-1] * n
    ans[-1] = n + 2 - i
    z = n + 1 - ans[-1]
    for i in range(1, n + 1):
        if i == ans[-1]:
            continue
        y = n + 1 - i
        p = judge(f"? {' '.join((map(str, [y] * (n - 1) + [z])))}")
        ans[p - 1] = i
    print("!", *ans)
    
    
    
for _ in range(1):
    main()