import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    flg = False
    bef = "0"
    cnt = 0
    for s in S:
        if s == bef:

            flg = False
            continue
        else:
            if not flg:
                flg = True
            else:
                
                cnt += 1
                bef = s
                flg = False
    
    print("YES" if cnt < 2 else "NO")
    
for _ in range(int(input())):
    main()