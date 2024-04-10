import sys
input = sys.stdin.readline

def main():
    s = input().strip()
    if s == "{}":
        print(0)
        return
    s = set(s[1:-1].split(", "))
    print(len(s))

main()