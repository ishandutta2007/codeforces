import sys
input = sys.stdin.readline

def main():
    s = input().strip()
    ans = s[0].upper() + s[1:]
    print(ans)

main()