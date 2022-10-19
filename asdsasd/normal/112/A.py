import sys
input = sys.stdin.readline

def main():
    s1 = input().strip().lower()
    s2 = input().strip().lower()
    if s1 == s2:
        print(0)
    elif s1 < s2:
        print(-1)
    else:
        print(1)

main()