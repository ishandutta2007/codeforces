import sys
input = sys.stdin.readline

def solve():
    a, b, ab, ba = map(int, input().split())
    S = input().strip()
    aa = a + ab + ba
    bb = b + ab + ba
    if aa != S.count("A")  or bb != S.count("B"):
        print("NO")
        return
    ind = [0]
    n = len(S)
    for i in range(1, n):
        if S[i - 1] == S[i]:
            ind.append(i)
    ind.append(n)
    tot = 0
    A = []
    B = []

    def solve(l, r):
        nonlocal tot, A, B
        le = r - l
        if le == 1:
            return
        elif le & 1:
            tot += le // 2
        else:
            x = le // 2
            if S[l] == "A":
                A.append(x)
            else:
                B.append(x)

    for i in range(len(ind) - 1):
        solve(ind[i], ind[i + 1])

    A.sort()
    B.sort()
    for a in A:
        if ab >= a:
            ab -= a
        else:
            a -= ab
            ab = 0
            ba -= a - 1
            ba = max(ba, 0)
    for b in B:
        if ba >= b:
            ba -= b
        else:
            b -= ba
            ba = 0
            ab -= b - 1
            ab = max(ab, 0)
    if tot >= max(0, ab) + max(0, ba):
        print("YES")
    else:
        print("NO")
    
for _ in range(int(input())):
    solve()