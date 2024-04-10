import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    alst.sort()
    minus = []
    plus = []
    zero = False
    for a in alst:
        if a < 0:
            minus.append(a)
        elif a > 0:
            plus.append(a)
        if a == 0:
            zero = True
    if len(minus) + len(plus) < 5:
        print(0)
        return
    
    plus = plus[::-1]
    ans = -10 ** 20
    if zero:
        ans = 0
    if len(plus) == 0:
        if zero:
            print(0)
            return
        minus.sort(reverse = True)
        ans = 1
        for a in minus[:5]:
            ans *= a
        print(ans)
        return
    for i in range(6):
        tmp = 1
        try:
            for j in range(i):
                tmp *= plus[j]
            for j in range(5 - i):
                tmp *= minus[j]
            ans = max(ans, tmp)
        except IndexError:
            pass
    print(ans)
            
for _ in range(int(input())):
    main()