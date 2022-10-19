import sys
input = sys.stdin.readline

def main():
    a, b = map(int, input().split())
    print(a^b)
    
for _ in range(int(input())):
    main()