import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    l = len(S)
    if l % 2 == 1:
        print("NO")
        return
    cl = S.count("(")
    cr = S.count(")")
    l //= 2
    if cl > l or cr > l:
        print("NO")
        return
    cnt = 0
    for s in S:
        if s == "?":
            if cl < l:
                s = "("
                cl += 1
            else:
                s = ")"
        if s == "(":
            cnt += 1
        else:
            cnt -= 1
        if cnt < 0:
            print("NO")
            return
    print("YES")
        
    
for _ in range(int(input())):
    main()