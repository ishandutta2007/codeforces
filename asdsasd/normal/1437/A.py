import sys
input = sys.stdin.readline

def main():
    l, r = map(int, input().split())
    if l * 2 <= r:
        print("NO")
    else:
        print("YES")
    
for _ in range(int(input())):
    main()