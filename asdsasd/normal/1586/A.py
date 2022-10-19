import sys
input = sys.stdin.readline

def isprime(x):
    if x <= 1: return False
    for i in range(2, int(x ** 0.5 + 1)):
        if x % i == 0:
            return False
    return True

def main():
    n = int(input())
    A = list(map(int, input().split()))
    tot = sum(A)
    if not isprime(tot):
        print(n)
        print(*range(1, n + 1))
    else:
        print(n - 1)
        for i in range(n):
            if A[i] % 2 == 1:
                ans = list(range(1, i + 1)) + list(range(i + 2, n + 1))
                print(*ans)
                return
    
for _ in range(int(input())):
    main()