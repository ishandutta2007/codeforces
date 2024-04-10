import sys
input = sys.stdin.readline

def main():
    k, n, w = map(int, input().split())
    money = k * w * (w + 1) // 2
    print(max(0, money - n))

main()