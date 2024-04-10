import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = list(input().strip())
    bef = ""
    rg = {"B":"R", "R":"B"}
    for i, s in enumerate(S):
        if s == "?":
            if bef != "":
                S[i] = rg[bef]
                bef = rg[bef]
        else:
            bef = s
    if S[-1] == "?":
        S[-1] = "B"
    bef = ""
    for i in range(n - 1, -1, -1):
        s = S[i]
        if s == "?":
            if bef != "":
                S[i] = rg[bef]
                bef = rg[bef]
        else:
            bef = s
    print("".join(S))
    
for _ in range(int(input())):
    main()