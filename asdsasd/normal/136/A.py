import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    ans = [-1 for _ in range(n)]
    for i, a in enumerate(alst, start = 1):
        ans[a - 1] = i
    print(*ans)
    
main()