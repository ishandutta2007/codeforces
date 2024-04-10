import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    A.sort()
    l = 0
    ans = 0
    for r in range(n):
        while A[l] + 5 < A[r]:
            l += 1
        ans = max(ans, r - l + 1)
    print(ans)
    
for _ in range(1):
    main()