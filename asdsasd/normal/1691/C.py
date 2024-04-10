import sys
input = sys.stdin.readline

def solve():
    n, k = map(int, input().split())
    S = input().strip()
    cnt = [0, 0]
    for s in S:
        cnt[int(s)] += 1
    if cnt[1] == 0:
        ans = 0
    elif cnt[0] == 0:
        ans = 11 * (cnt[1] - 1)
    elif cnt[1] == 1:
        ind = S.index("1")
        d1 = n - 1 - ind
        d2 = ind
        if d1 <= k:
            ans = 1
        elif d2 <= k:
            ans = 10
        else:
            ans = 11
    else:
        ind1 = S.index("1")
        ind2 = S[::-1].index("1")
        if ind1 + ind2 <= k:
            ans = 11 * cnt[1] - 11
        elif ind2 <= k:
            ans = 11 * cnt[1] - 10
        elif ind1 <= k:
            ans = 11 * cnt[1] - 1
        else:
            ans = 11 * cnt[1]
    print(ans)

    
for _ in range(int(input())):
    solve()