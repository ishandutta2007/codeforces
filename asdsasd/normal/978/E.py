import sys
input = sys.stdin.readline

def main():
    n, w = map(int, input().split())
    A = list(map(int, input().split()))
    min_ = 0
    max_ = 0
    tot = 0
    for a in A:
        tot += a
        min_ = min(min_, tot)
        max_ = max(max_, tot)
    print(max(0, w - (max_ - min_) + 1))
    
    
for _ in range(1):
    main()