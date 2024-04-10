import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    cnt = [0] * n
    flst = []
    for _ in range(m):
        k, *lst = list(map(int, input().split()))
        flst.append((k, lst))
        if k == 1:
            cnt[lst[0] - 1] += 1
        else:
            continue
    
    ans = []
    ok = (m + 1) // 2
    for c in cnt:
        if c > ok:
            print("NO")
            return
    
    for k, lst in flst:
        if k == 1:
            ans.append(lst[0])
        else:
            flg = True
            for c in lst:
                if cnt[c - 1] < ok:
                    cnt[c - 1] += 1
                    ans.append(c)
                    flg = False
                    break
            if flg:
                print("NO")
                return
                
    print("YES")
    print(*ans)
    
    
for _ in range(int(input())):
    main()