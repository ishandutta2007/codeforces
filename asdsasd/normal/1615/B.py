import sys
input = sys.stdin.readline

def main():
    l, r = map(int, input().split())
    l -= 1
    max_ = 0
    mod = 2
    x = 1
    
    def f(y, x, mod):
        ret = y // mod * x
        ret += max(0, y % mod - x + 1)
        return ret
    
    for _ in range(20):
        tmp = f(r, x, mod) - f(l, x, mod)
        max_ = max(max_, tmp)
        x *= 2
        mod *= 2
    print(r - l - max_)
        
    
    
for _ in range(int(input())):
    main()