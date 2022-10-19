def solve():
    n = int(input())
    wlst = list(map(int, input().split()))
    cand = []
    cnt = 0
    wlst.sort()
    bef = wlst[0]
    for w in wlst:
        if w == bef:
            cnt += 1
        else:
            cand.append([bef, cnt])
            cnt = 1
        bef = w
    cand.append([bef, cnt])
    l = len(cand)
    ans = [0 for _ in range(2 * n + 1)]
    for i in range(l):
        wi = cand[i][0]
        ci = cand[i][1]
        ans[wi * 2] += ci // 2
        for j in range(i + 1, l):
            wj = cand[j][0]
            cj = cand[j][1]
            ans[wi + wj] += min(ci, cj)
    print(max(ans))


t = int(input())
for _ in range(t):
    solve()