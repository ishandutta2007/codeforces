import sys
input = sys.stdin.readline

def main():
    input()
    n, m = map(int, input().split())
    rc = [list(map(int, input().split())) for _ in range(m)]
    if m % 2 == 1:
        print("NO")
        return
    rc.sort(key = lambda x:x[1])
    typ = 0
    """
    0: .  1:*  2:.
    0: .  1:.  2:*
    """
    bef = 0
    for r, c in rc:
        if bef == c:
            if typ == 0:
                print("NO")
                return
            
        if typ == 0:
            if r == 1:
                typ = 1
            else:
                typ = 2
        elif typ == 1:
            if r == 1:
                if (c - bef) % 2 == 0:
                    print("NO")
                    return
                else:
                    typ = 0
            else:
                if (c - bef) % 2 == 0:
                    typ = 0
                else:
                    print("NO")
                    return
        else:
            if r == 1:
                if (c - bef) % 2 == 0:
                    typ = 0
                else:
                    print("NO")
                    return
            else:
                if (c - bef) % 2 == 0:
                    print("NO")
                    return
                else:
                    typ = 0
        bef = c
    
    if typ == 0:
        print("YES")
    else:
        print("NO")
    
for _ in range(int(input())):
    main()