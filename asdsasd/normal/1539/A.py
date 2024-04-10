import sys
input = sys.stdin.readline

def main():
    n, x, t = map(int, input().split())
    max_ = t // x
    if n <= max_:
        print(n * (n - 1) // 2)
    else:
        print(max_ * (max_ - 1) // 2 + max_ * (n - max_))
    
for _ in range(int(input())):
    main()