import sys
input = sys.stdin.readline

def main():
    m, n = map(int, input().split())
    print(m * n // 2)

main()