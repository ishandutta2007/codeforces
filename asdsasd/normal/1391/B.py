import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    conv = [input().strip() for _ in range(n)]
    ans = 0
    for i in range(m - 1):
        if conv[n - 1][i] == "D":
            ans += 1
    for i in range(n - 1):
        if conv[i][m - 1] == "R":
            ans += 1
    print(ans)


for _ in range(int(input())):
    main()