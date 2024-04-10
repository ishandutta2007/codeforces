import sys
input = sys.stdin.readline

def main():
    s = input().strip()
    t = input().strip()
    if s == t[::-1]:
        print("YES")
    else:
        print("NO")
    
main()