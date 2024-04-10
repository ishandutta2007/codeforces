import sys
input = sys.stdin.readline

def main():
    x, y, k = map(int, input().split())
    x -= 1
    ans = k + (k * y + k - 2) // x + 1
    print(ans)
    
for _ in range(int(input())):
    main()