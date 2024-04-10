import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ans = []
    
    x = 1
    bef = 0
    while 1:
        for i in range(x):
            ans.append((bef + x - i, bef + i + 1))
        bef += x
        r = n - bef - x
        x += 1
        if r <= x:
            for i in range(r):
                ans.append((n - i, n - i))
            break
    
    ans2 = []
    a = (n + 2) // 3
    b = a - 1
    for i in range(a, 0, -1):
        ans2.append((a - i + 1, i))
    for i in range(b, 0, -1):
        ans2.append((b - i + 1 + a, i + a))
    if n % 3 == 0:
        ans2.append((n, n))
    if len(ans2) < len(ans):
        ans = ans2
    print(len(ans))
    for row in ans:
        print(*row)
    
    
for _ in range(1):
    main()