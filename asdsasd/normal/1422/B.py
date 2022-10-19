import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    alst = [list(map(int, input().split())) for _ in range(n)]
    ans = 0
    for i in range(n // 2):
        for j in range(m // 2):
            lst = [alst[i][j], alst[n - 1 - i][j], 
                    alst[i][m - 1 - j], alst[n - 1 - i][m - 1 - j]]
            lst.sort()
            mean = lst[1]
            for num in lst:
                ans += abs(num - mean)
    if n % 2 == 1:
        for j in range(m // 2):
            num1 = alst[n // 2][j]
            num2 = alst[n // 2][m - 1 - j]
            ans += abs(num1 - num2)
    if m % 2 == 1:
        for i in range(n // 2):
            num1 = alst[i][m // 2]
            num2 = alst[n - 1 - i][m // 2]
            ans += abs(num1 - num2)
    
    print(ans)
            
    
for _ in range(int(input())):
    main()