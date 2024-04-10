import sys
input = sys.stdin.readline

def main():
    n = int(input())
    ab = [list(map(int, input().split())) for _ in range(n)]
    
    def ok(x):
        bb = 0
        aa = x - 1
        for a, b in ab:
            if a >= aa and b >= bb:
                if aa == 0:
                    return True
                aa -= 1
                bb += 1
        return False
    
    l = 1
    r = n + 1
    while r - l > 1:
        mid = (l + r) // 2
        if ok(mid):
            l = mid
        else:
            r = mid
    print(l)
    
for _ in range(int(input())):
    main()