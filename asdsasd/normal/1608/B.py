import sys
input = sys.stdin.readline

def main():
    n, a, b = map(int, input().split())
    if abs(a - b) > 1:
        print(-1)
        return
    elif a + b + 2 > n:
        print(-1)
        return
    if a == b:
        lst = list(range(1, n + 1))
        pl = 0
        pr = n - 1
        ans = []
        for i in range(n):
            if i == 0:
                ans.append(lst[pl])
                pl += 1
            elif a and i % 2 == 1:
                a -= 1
                ans.append(lst[pr])
                pr -= 1
            elif b and i % 2 == 0:
                b -= 1
                ans.append(lst[pl])
                pl += 1
            else:
                ans.append(lst[pl])
                pl += 1
        print(*ans)
    elif a > b:
        lst = list(range(1, n + 1))
        pl = 0
        pr = n - 1
        ans = []
        for i in range(n):
            if i == 0:
                ans.append(lst[pl])
                pl += 1
            elif a and i % 2 == 1:
                a -= 1
                ans.append(lst[pr])
                pr -= 1
            elif b and i % 2 == 0:
                b -= 1
                ans.append(lst[pl])
                pl += 1
            else:
                ans.append(lst[pr])
                pr -= 1
        print(*ans)
    else:
        lst = list(range(1, n + 1))
        pl = 0
        pr = n - 1
        ans = []
        for i in range(n):
            if i == 0:
                ans.append(lst[pr])
                pr -= 1
            elif b and i % 2 == 1:
                b -= 1
                ans.append(lst[pl])
                pl += 1
            elif b and i % 2 == 0:
                a -= 1
                ans.append(lst[pr])
                pr -= 1
            else:
                ans.append(lst[pl])
                pl += 1
        print(*ans)
            
    
    
for _ in range(int(input())):
    main()