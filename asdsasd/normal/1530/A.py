import sys
input = sys.stdin.readline

def main():
    print(max(map(int, input().strip())))
    
for _ in range(int(input())):
    main()