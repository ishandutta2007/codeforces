import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    A.append(1)
    ans = []
    for i in range(n):
        if A[i + 1] == 1:
            ans.append(A[i])
    print(len(ans))
    print(*ans)
    
for _ in range(1):
    main()