import sys
input = sys.stdin.readline

def main():
    n, K = map(int, input().split())
    A = list(map(int, input().split()))
    lst = []
    A.sort()
    cnt = 0
    bef = -1
    A.append(1 << 40)
    for a in A:
        if a != bef:
            if cnt >= K:
                lst.append(bef)
            cnt = 1
        else:
            cnt += 1
        bef = a
    max_ = -1
    ans = [-1]
    l = -1
    bef = -1
    for r in lst:
        if r != bef + 1:
            if l != -1 and bef - l > max_:
                max_ = bef - l
                ans = (l, bef)
            l = r
        bef = r
    if l != -1 and bef - l > max_:
        max_ = bef - l
        ans = (l, bef)
    
    print(*ans)


    


for _ in range(int(input())):
    main()