import sys
input = sys.stdin.readline
"""
from pprint import pprint
n = 5
P = [3, 4, 5, 2, 1]
q = [i for i in range(1, n + 1)]

def print(Q, flush):
    pprint(Q)
    if Q[0] == "!":
        return
    i = int(Q[2:]) - 1
    global x, q
    x = str(q[i])
    q = [q[P[i] - 1] for i in range(n)]
    
def input():
    return x
"""
def ask(Q):
    print(Q, flush = True)
    if Q[0] == "!":
        return
    return int(input())
    


def main():
    n = int(input())
    used = [False] * n
    lst = []
    cnt = -1
    for i in range(n):
        if used[i]:
            continue
        tmp = []
        while 1:
            x = ask(f"? {i + 1}") - 1
            cnt += 1
            if used[x]:
                break
            tmp.append((cnt, x + 1))
            used[x] = True
        lst.append(tmp)
    ans = [-1] * n
    for tmp in lst:
        l = len(tmp)
        c = tmp[0][0]
        xx = [x for _, x in tmp]
        c %= l
        xx = xx[c:] + xx[:c]
        for i in range(l):
            a = xx[i - 1]
            b = xx[i]
            ans[a - 1] = b
    ans = " ".join(map(str, ans))
    ask(f"! {ans}")
    

for _ in range(int(input())):
    main()