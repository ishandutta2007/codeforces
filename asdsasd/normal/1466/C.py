import sys
input = sys.stdin.readline

def main():
    S = list(input().strip())
    ans = 0
    l = len(S)
    if l == 1:
        print(0)
        return
    if S[0] == S[1]:
        ans += 1
        S[1] = "1"
    for i in range(1, l - 1):
        if S[i] == S[i + 1] or S[i - 1] == S[i + 1]:
            ans += 1
            S[i + 1] = str(i + 1)
    print(ans)
    
for _ in range(int(input())):
    main()