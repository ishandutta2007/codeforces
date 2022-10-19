import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    ans = 0
    for i in range(n - 1):
        ans = max(ans, alst[i] * alst[i + 1])
    print(ans)
    
for _ in range(int(input())):
    main()