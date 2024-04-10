import sys
input = sys.stdin.readline

def main():
    N = list(input().strip())
    cnt = [0] * 10
    for n in N:
        cnt[int(n)] += 1
    n = len(N)
    N = N[::-1]
    inf = 10 ** 20
    ans = inf
    if cnt[0] >= 2:
        tmp = 0
        c = 0
        for i in range(n):
            if N[i] == "0":
                tmp += i - c
                c += 1
                if c == 2:
                    break
        ans = min(ans, tmp)
    
    for a, b in [[2, 5], [5, 0], [7, 5]]:
        if cnt[a] == 0 or cnt[b] == 0:
            continue
        c = -1
        d = -1
        for i in range(n):
            if c == -1 and N[i] == str(a):
                c = i
            elif d == -1 and N[i] == str(b):
                d = i
        if d > c:
            c += 1
        if n >= 3 and n - 1 in [c, d]:
            if n - 2 in [c, d]:
                br = False
                for i in range(n - 3, -1, -1):
                    if N[i] == "0":
                        c += 1
                    else:
                        br = True
                        break
                if not br:
                    c = 2 * inf
            else:
                for i in range(n - 2, -1, -1):
                    if N[i] == "0":
                        c += 1
                    else:
                        br = True
                        break
                if not br:
                    c = 2 * inf
        
        ans = min(ans, c + d - 1)
    if ans == inf:
        print(-1)
    else:
        print(ans)
                
        
        
    
    
for _ in range(1):
    main()