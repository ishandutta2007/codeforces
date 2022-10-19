import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    a_cnt = S.count("A")
    b_cnt = S.count("B")
    c_cnt = S.count("C")
    
    for aa in (1, -1):
        for bb in (1, -1):
            for cc in (1, -1):
                flg = True
                tot = 0
                for s in S:
                    if s == "A":
                        tot += aa
                    elif s == "B":
                        tot += bb
                    else:
                        tot += cc
                    if tot < 0:
                        flg = False
                        break
                if flg and tot == 0:
                    print("YES")
                    return
    print("NO")
    
for _ in range(int(input())):
    main()