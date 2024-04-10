import sys
input = sys.stdin.readline

def main():
    n = input().strip()
    cnt = n.count("4") + n.count("7")
    if cnt in [4, 7, 14, 17]:
        print("YES")
    else:
        print("NO")

main()