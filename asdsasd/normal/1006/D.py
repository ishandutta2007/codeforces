import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    T = input().strip()
    ans = 0
    for i in range(n // 2):
        s1 = S[i]
        s2 = S[n - 1 - i]
        t1 = T[i]
        t2 = T[n - 1 - i]
        if t1 == t2:
            ans += s1 != s2
        else:
            if s1 == t1:
                t1 = ""
                s1 = ""
            elif s1 == t2:
                t2 = ""
                s1 = ""
            if s2 == t1:
                t1 = ""
                s2 = ""
            elif s2 == t2:
                t2 = ""
                s2 = ""
            ans += (s1 != "") + (s2 != "")
    if n % 2 == 1:
        if S[n // 2] != T[n // 2]:
            ans += 1
    print(ans)
    
    
for _ in range(1):
    main()