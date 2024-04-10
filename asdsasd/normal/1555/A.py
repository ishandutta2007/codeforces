import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ans = float("inf")
    for i in range(10):
        for j in range(10):
            m = n - 6 * i - 8 * j
            k = max(0, (m + 9) // 10)
            ans = min(ans, 15 * i + 20 * j + 25 * k)
    print(ans)
    
for _ in range(int(input())):
    main()