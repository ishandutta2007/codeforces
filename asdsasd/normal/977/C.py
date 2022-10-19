import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    A.sort()
    if n == k:
        print(A[-1])
    elif k == 0:
        if A[0] == 1:
            print(-1)
        else:
            print(1)
    elif A[k - 1] == A[k]:
        print(-1)
    else:
        print(A[k - 1])
    
    
    
for _ in range(1):
    main()