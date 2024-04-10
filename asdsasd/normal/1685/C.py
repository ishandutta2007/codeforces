import sys
input = sys.stdin.readline

def solve():
    n = int(input()) * 2
    S = input().strip()
    tot = 0
    ok = True
    cum = [0]
    for s in S:
        if s == "(":
            tot += 1
        else:
            tot -= 1
            if tot < 0:
                ok = False
        cum.append(tot)
    if ok:
        print(0)
        return
    for i in range(n + 1):
        if cum[i] < 0:
            break
    ma = -1
    for j in range(i - 1, -1, -1):
        if cum[j] > ma:
            ma = cum[j]
            lind = j
    for i in range(n, -1, -1):
        if cum[i] < 0:
            break
    ma = -1
    for j in range(i + 1, n + 1):
        if cum[j] > ma:
            ma = cum[j]
            rind = j
    T = S[:lind] + S[lind:rind][::-1] + S[rind:]
    ok = True
    tot = 0
    for t in T:
        if t == "(":
            tot += 1
        else:
            tot -= 1
            if tot < 0:
                ok = False
    if ok:
        print(1)
        print(lind + 1, rind)
        return

    print(2)
    ma = 0
    tot = 0
    for i in range(n):
        if S[i] == "(":
            tot += 1
            if tot >= ma:
                ma = tot
                ind = i
        else:
            tot -= 1
    print(1, ind + 1)
    S = S[:ind+1][::-1] + S[ind+1:]
    ma = 0
    tot = 0
    for i in range(n - 1, -1, -1):
        if S[i] == ")":
            tot += 1
            if tot >= ma:
                ma = tot
                ind = i
        else:
            tot -= 1
    print(ind + 1, n)
    
for _ in range(int(input())):
    solve()