import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    string = input().strip()
    if "W" not in string:
        ans = min(n, k) * 2 - 1
        print(max(ans, 0))
        return
        
    L_s = []
    cnt = 0
    bef = string[0]
    ans = 0
    for s in string:
        if s == bef:
            cnt += 1
        else:
            if bef == "L":
                L_s.append(cnt)
            else:
                ans += cnt * 2 - 1
            cnt = 1
        bef = s
    if bef == "W":
        ans += cnt * 2 - 1
        cnt = 0
        
    if string[0] == "L" and L_s:
        cnt += L_s[0]
        L_s = L_s[1:]
    L_s.sort()
    for l in L_s:
        if k >= l:
            ans += l * 2 + 1
            k -= l
        else:
            ans += k * 2
            k = 0
            
    ans += 2 * min(k, cnt)
    print(ans)
    
    
    
for _ in range(int(input())):
    main()