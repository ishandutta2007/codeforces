import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    T = input().strip()
    ls = len(S)
    lt = len(T)
    if lt > ls:
        print("No")
        return
    if T == S[-lt:]:
        print("Yes")
        return
        
    tpos = 0
    S = S[::-1]
    T = T[::-1]
    flg = False
    for s in S:
        if flg:
            flg = False
        elif T[tpos] == s:
            tpos += 1
            if tpos == lt:
                print("Yes")
                return
        else:
            flg = True
    print("No")
            
        
        
    
    
for _ in range(int(input())):
    main()