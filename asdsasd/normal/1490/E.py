import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    blst = sorted(alst)
    l = -1
    r = n - 1
    while r - l > 1:
        mid = (r + l) // 2
        total = sum(blst[:mid + 1])
        for i in range(mid + 1, n):
            if blst[i] > total:
                l = mid
                break
            total += blst[i]
        else:
            r = mid
    th = blst[r]
    ans = []
    for i, a in enumerate(alst, 1):
        if a >= th:
            ans.append(i)
    print(len(ans))
    print(*ans)
    
    
for _ in range(int(input())):
    main()