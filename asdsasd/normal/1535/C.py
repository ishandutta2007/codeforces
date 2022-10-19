import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    n = len(S)
    p1 = [False] * n
    p2 = [False] * n
    p3 = [False] * n
    for i, s in enumerate(S):
        if s == "?":
            p1[i] = p2[i] = p3[i] = True
        elif (s == "1") ^ (i % 2 == 0):
            p1[i] = True
        else:
            p2[i] = True
    ans = 0
    bef = -1
    for i, t in enumerate(p1):
        if t:
            ans += i - bef
        else:
            bef = i
    bef = -1
    for i, t in enumerate(p2):
        if t:
            ans += i - bef
        else:
            bef = i
    bef = -1
    for i, t in enumerate(p3):
        if t:
            ans -= i - bef
        else:
            bef = i
    print(ans)
    
for _ in range(int(input())):
    main()