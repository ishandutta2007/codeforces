import sys
input = sys.stdin.readline

def main():
    n = int(input())
    print((n + 1) // 10)
    
for _ in range(int(input())):
    main()