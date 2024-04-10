import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    alst = list(map(int, input().split()))
    ans = -10 ** 10
    for i in range(n - 1, -1, -1):
        for j in range(i - 1, -1, -1):
            if (i + 1) * (j + 1) < ans:
                break
            ans = max(ans, (i + 1) * (j + 1) - k * (alst[i] | alst[j]))
    print(ans)
    
for _ in range(int(input())):
    main()