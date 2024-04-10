import sys
input = sys.stdin.readline

def main():
    n, t = map(int, input().split())
    s = list(input().strip())
    for _ in range(t):
        flg = False
        for i in range(n - 1):
            if flg:
                flg = False
            elif s[i] == "B" and s[i + 1] == "G":
                s[i] = "G"
                s[i + 1] = "B"
                flg = True
    print("".join(s))

main()