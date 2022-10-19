import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    ans = 1 << 60
    for i in range(n):
        cnt = 0
        bef = 0
        for j in range(i - 1, -1, -1):
            x = bef // A[j] + 1
            cnt += x
            bef = x * A[j]
        bef = 0
        for j in range(i + 1, n):
            x = bef // A[j] + 1
            cnt += x
            bef = x * A[j]
        ans = min(ans, cnt)
    print(ans)
    
    
for _ in range(1):
    main()