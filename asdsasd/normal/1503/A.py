import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    l = S.count("1")
    o = S.count("0")
    if l % 2 == 1:
        print("NO")
        return
    if S[0] == "0" or S[-1] == "0":
        print("NO")
        return
    
    print("YES")
    cnt_o = 0
    cnt_l = 0
    T1 = []
    T2 = []
    for s in S:
        if s == "1":
            if cnt_l < l // 2:
                T1.append("(")
                T2.append("(")
            else:
                T1.append(")")
                T2.append(")")
            cnt_l += 1
        else:
            cnt_o += 1
            if cnt_o % 2 == 0:
                T1.append("(")
                T2.append(")")
            else:
                T1.append(")")
                T2.append("(")
    print("".join(T1))
    print("".join(T2))
    
for _ in range(int(input())):
    main()