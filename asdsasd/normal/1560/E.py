import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    used = [False] * 26
    cnt = [0] * 26
    T = []
    for s in S[::-1]:
        p = ord(s) - 97
        if not used[p]:
            used[p] = True
            T.append(s)
        cnt[p] += 1
    T = T[::-1]
    l = len(T)
    tot = 0
    for i, t in enumerate(T, 1):
        p = ord(t) - 97
        if cnt[p] % i != 0:
            print(-1)
            return
        tot += cnt[p] // i
    
    R = S[:tot]
    p = 0
    se = set()
    n = len(S)
    for i in range(l):
        for r in R:
            if r in se:
                continue
            if p >= n or r != S[p]:
                print(-1)
                return
            p += 1
        se.add(T[i])
    print(R, "".join(T))
    
for _ in range(int(input())):
    main()