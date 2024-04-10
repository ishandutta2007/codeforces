import sys
input = sys.stdin.readline

def main():
    n, s = map(int, input().split())
    print(s // ((n + 2) // 2))
    
for _ in range(int(input())):
    main()