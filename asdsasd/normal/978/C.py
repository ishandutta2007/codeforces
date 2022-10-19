import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    tot = 0
    p = 0
    for b in B:
        while b - tot > A[p]:
            tot += A[p]
            p += 1
        print(p + 1, b - tot)
    
    
for _ in range(1):
    main()