import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    if n % 2 == 1:
        print("YES")
        ans = []
        for i in range(3, n + 1, 2):
            ans.append([i - 2, i - 1, i])
        for i in range(3, n - 1, 2):
            ans.append([i - 2, i - 1, n])
        print(len(ans))
        for row in ans:
            print(*row)
    else:
        tmp = 0
        for a in alst:
            tmp ^= a
        if tmp != 0:
            print("NO")
            return
        print("YES")
        ans = []
        for i in range(3, n + 1, 2):
            ans.append([i - 2, i - 1, i])
        for i in range(3, n - 1, 2):
            ans.append([i - 2, i - 1, n])
        print(len(ans))
        for row in ans:
            print(*row)
    
for _ in range(1):
    main()