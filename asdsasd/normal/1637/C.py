import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    A = A[1:n-1]
    n -= 2
    if all(a <= 1 for a in A):
        print(-1)
        return
    elif n == 1:
        a = A[0]
        if a % 2 == 0:
            print(a // 2)
        else:
            print(-1)
        return
    ans = 0
    for a in A:
        ans += a // 2
        if a % 2 == 1:
            ans += 1
    print(ans)
    
    
    
for _ in range(int(input())):
    main()