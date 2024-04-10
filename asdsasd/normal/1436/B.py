import sys
input = sys.stdin.readline

num = [1, 9, 15, 21, 25, 27, 33, 35, 39, 42, 45, 49, 51, 55, 57, 63, 65, 69, 75, 77]
def isprime(n):
    for i in range(2, int(n ** 0.5 + 1)):
        if n % i == 0:
            return False
    return True
    
def main():
    n = int(input())
    ans = [4] * (n - 1)
    total = 4 * (n - 1)
    for i in num:
        if isprime(total + i):
            ans.append(i)
            break
    for _ in range(n):
        print(*ans)
        ans = [ans[-1]] + ans[:-1]
    
for _ in range(int(input())):
    main()