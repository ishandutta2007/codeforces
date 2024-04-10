import sys
input = sys.stdin.readline

def main():
    n, p, k = map(int, input().split())
    alst = input().strip()
    x, y = map(int, input().split())
    cnt = [0 for _ in range(k)]
    ans = 10 ** 30
    for i in range(n - 1, p - 2, -1):
        if alst[i] == "0":
            cnt[(i - p + 1) % k] += 1
        ans = min(ans, cnt[(i - p + 1) % k] * x + (i - p + 1) * y)
    
    print(ans)
    
for _ in range(int(input())):
    main()