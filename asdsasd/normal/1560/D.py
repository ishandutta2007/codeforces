import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    ans = 10 ** 10
    n = len(S)
    for T in lst:
        p = 0
        for s in S:
            if s == T[p]:
                p += 1
        ans = min(ans, n + len(T) - 1 - 2 * p)
    print(ans)
    
lst = []
x = 1
while x <= 10 ** 20:
    lst.append(str(x) + "=")
    x *= 2


for _ in range(int(input())):
    main()