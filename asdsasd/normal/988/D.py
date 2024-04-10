import sys
input = sys.stdin.readline

def main():
    n = int(input())
    X = set(map(int, input().split()))
    for x in X:
        lst = [x]
        break
    ans = 1
    for x in X:
        y = 1
        while y <= 2 * 10 ** 9:
            if x + y in X:
                if x + y * 2 in X:
                    print(3)
                    print(x, x + y, x + 2 * y)
                    return
                elif ans == 1:
                    ans = 2
                    lst = [x, x + y]
                        
            y *= 2
    print(ans)
    print(*lst)
    
for _ in range(1):
    main()