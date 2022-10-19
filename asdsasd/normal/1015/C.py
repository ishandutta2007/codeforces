import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    A = []
    B = []
    D = []
    tot = 0
    for _ in range(n):
        a, b = map(int, input().split())
        tot += b
        A.append(a)
        B.append(b)
        D.append(a - b)
    if tot > m:
        print(-1)
        return
    D.sort()
    for i, d in enumerate(D):
        tot += d
        if tot > m:
            print(n - i)
            return
    print(0)
    
for _ in range(1):
    main()