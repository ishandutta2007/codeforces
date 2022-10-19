import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = list(input().strip())
    T = list(input().strip())
    ans = 0
    for i in range(n):
        if S[i] != T[i]:
            ans += 2
            S[i] = "2"
            T[i] = "2"
        elif S[i] == "0":
            ans += 1
            if i > 0 and S[i - 1] == "1":
                ans += 1
                S[i] = "2"
                T[i] = "2"
        else:
            if i > 0 and S[i - 1] == "0":
                ans += 1
                S[i] = "2"
                T[i] = "2"
    print(ans)
    
for _ in range(int(input())):
    main()