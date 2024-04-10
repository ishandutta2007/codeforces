import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    alst = list(map(int, input().split()))
    xlst = list(map(int, input().split()))
    total = 0
    rui_max = [0]
    for i, a in enumerate(alst):
        total += a
        rui_max.append(max(rui_max[-1], total))
    ans = []
    for x in xlst:
        if total <= 0:
            if rui_max[-1] < x:
                ans.append(-1)
            else:
                l = 0
                r = n
                while r - l > 1:
                    mid = (r + l) // 2
                    if rui_max[mid] >= x:
                        r = mid
                    else:
                        l = mid
                ans.append(l)
            continue
        
        loop = max(0,(x - rui_max[-1] + total - 1) // total)
        l = 0
        r = n
        while r - l > 1:
            mid = (r + l) // 2
            if max(0,(x - rui_max[mid] + total - 1) // total) == loop:
                r = mid
            else:
                l = mid
        ans.append(loop * n + l)
    print(*ans)
        
    
for _ in range(int(input())):
    main()