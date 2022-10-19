import sys
input = sys.stdin.readline

def main():
    a, b = map(int, input().split())
    print((b - a) % b)

for _ in range(int(input())):
    main()