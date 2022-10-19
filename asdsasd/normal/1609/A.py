import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    x = 1
    for i in range(n):
        while A[i] % 2 == 0:
            x *= 2
            A[i] //= 2
    print(sum(A) + max(A) * x - max(A))
    
for _ in range(int(input())):
    main()