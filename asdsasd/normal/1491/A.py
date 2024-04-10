import sys
input = sys.stdin.readline

def main():
    n, q = map(int, input().split())
    alst = list(map(int, input().split()))
    zero = alst.count(0)
    one = n - zero
    for _ in range(q):
        t, x = map(int, input().split())
        if t == 1:
            x -= 1
            if alst[x] == 0:
                zero -= 1
                one += 1
            else:
                zero += 1
                one -= 1
            alst[x] = 1 - alst[x]
        else:
            if one >= x: print(1)
            else: print(0)
                
    
for _ in range(1):
    main()