import sys
input = sys.stdin.readline

def main():
    l, r = map(int, input().split())
    max_ = (r - 1) // 2
    if r - max_ >= l:
        print(max_)
    else:
        print(r - l)
    
for _ in range(int(input())):
    main()