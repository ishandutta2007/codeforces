import sys
input = sys.stdin.readline

def main():
    n = int(input())
    s = input().strip()
    bef = ""
    ans = 0
    for ss in s:
        if ss == bef:
            ans += 1
        bef = ss
    print(ans)

main()