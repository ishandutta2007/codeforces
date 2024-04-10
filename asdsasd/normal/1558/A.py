import sys
input = sys.stdin.readline

def main():
    a, b = map(int, input().split())
    if (a + b) % 2 == 0:
        min_ = abs(a - b) // 2
        max_ = min(a, b) * 2 + (abs(a - b)) // 2
        ans = [i for i in range(min_, max_ + 1, 2)]
    else:
        min_ = abs(a - b) // 2
        max_ = min(a, b) * 2 + min_ + 1
        ans = [i for i in range(min_, max_ + 1)]
    print(len(ans))
    print(*ans)
    
    
for _ in range(int(input())):
    main()