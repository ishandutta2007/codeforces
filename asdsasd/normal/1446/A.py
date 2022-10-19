import sys
input = sys.stdin.readline

def main():
    n, W = map(int, input().split())
    wlst = list(map(int, input().split()))
    lower = (W + 1) // 2
    total = 0
    ans = []
    for i, w in enumerate(wlst, 1):
        if lower <= w <= W:
            print(1)
            print(i)
            return
        if w <= lower:
            total += w
            ans.append(i)
            if total >= lower:
                break
    else:
        print(-1)
        return
    ans.sort()
    print(len(ans))
    print(*ans)
    
for _ in range(int(input())):
    main()