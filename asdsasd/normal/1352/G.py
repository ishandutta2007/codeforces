import sys
input = sys.stdin.readline

def main():
    n = int(input())
    if n == 2 or n == 3:
        print(-1)
        return
    if n % 4 == 0:
        ans = []
        for i in range(n // 4):
            ans.append(i * 4 + 2)
            ans.append(i * 4 + 4)
            ans.append(i * 4 + 1)
            ans.append(i * 4 + 3)
        print(*ans)
    elif n % 4 == 1:
        ans = []
        for i in range(n // 4):
            ans.append(i * 4 + 2)
            ans.append(i * 4 + 4)
            ans.append(i * 4 + 1)
            ans.append(i * 4 + 3)
        ans.append(n)
        print(*ans)
    elif n % 4 == 2:
        ans = []
        for i in range(n // 4 - 1):
            ans.append(i * 4 + 2)
            ans.append(i * 4 + 4)
            ans.append(i * 4 + 1)
            ans.append(i * 4 + 3)
        ans += [n - 4, n - 2, n - 5, n - 1, n - 3, n]
        print(*ans)
    else:
        ans = []
        for i in range(n // 4 - 1):
            ans.append(i * 4 + 2)
            ans.append(i * 4 + 4)
            ans.append(i * 4 + 1)
            ans.append(i * 4 + 3)
        ans += [n - 5, n - 3, n - 6, n - 2, n, n - 4, n - 1]
        print(*ans)
        
    
for _ in range(int(input())):
    main()