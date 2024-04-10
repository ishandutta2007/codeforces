import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    if ">" not in S or "<" not in S:
        print(n)
    else:
        ans = 0
        for i in range(n):
            if S[i - 1] == "-" or S[i] == "-":
                ans += 1
        print(ans)

for _ in range(int(input())):
    main()