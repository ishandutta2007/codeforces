import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    ans = 0
    
    def f(a, b):
        if b < a:
            a, b = b, a
        ret = 0
        while a * 2 < b:
            a *= 2
            ret += 1
        return ret
    
    for i in range(n - 1):
        ans += f(alst[i], alst[i + 1])
    print(ans)
    
for _ in range(int(input())):
    main()