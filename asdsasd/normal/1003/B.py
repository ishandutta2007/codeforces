import sys
input = sys.stdin.readline

def main():
    a, b, x = map(int, input().split())
    ans = []
    if x % 2 == 1:
        for _ in range(x // 2):
            ans.append(0)
            ans.append(1)
            a -= 1
            b -= 1
        ans += [0] * a
        ans += [1] * b
    elif a > b:
        ans.append(0)
        a -= 1
        for _ in range(x // 2 - 1):
            ans.append(1)
            ans.append(0)
            a -= 1
            b -= 1
        ans += [1] * b
        ans += [0] * a
    else:
        ans.append(1)
        b -= 1
        for _ in range(x // 2 - 1):
            ans.append(0)
            ans.append(1)
            a -= 1
            b -= 1
        ans += [0] * a
        ans += [1] * b
    print(*ans, sep="")
    
for _ in range(1):
    main()