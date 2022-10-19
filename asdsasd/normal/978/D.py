import sys
input = sys.stdin.readline

def main():
    n = int(input())
    B = list(map(int, input().split()))
    if n <= 2:
        print(0)
        return
    inf = 10 ** 20
    ans = inf
    
    for d1 in range(-1, 2):
        for d2 in range(-1, 2):
            tmp = abs(d1) + abs(d2)
            a = B[1] + d2
            d = (B[1] + d2) - (B[0] + d1)
            ng = False
            for b in B[2:]:
                a += d
                if abs(a - b) <= 1:
                    tmp += abs(a - b)
                else:
                    ng = True
                    break
            if not ng:
                ans = min(ans, tmp)
    
    if ans == inf:
        print(-1)
    else:
        print(ans)
    
    
for _ in range(1):
    main()