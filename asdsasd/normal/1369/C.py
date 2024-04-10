import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    alst = list(map(int, input().split()))
    wlst = list(map(int, input().split()))
    alst.sort()
    wlst.sort(reverse = True)
    pos_l = 0
    pos_r = n - 1
    lst = [[] for _ in range(k)]
    ans = 0
    for i, w in enumerate(wlst):
        for _ in range(w - 1):
            lst[i].append(alst[pos_l])
            pos_l += 1
    for i, w in enumerate(wlst[::-1]):
        lst[k - 1 - i].append(alst[pos_r])
        pos_r -= 1
    for l in lst:
        ans += max(l) + min(l)
    print(ans)
    
    
for _ in range(int(input())):
    main()