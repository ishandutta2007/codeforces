import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    lr = 1
    l = 0
    r = n - 1
    while r >= l:
        if lr:
            print(alst[l], end = " ")
            l += 1
        else:
            print(alst[r], end = " ")
            r -= 1
        lr = 1 - lr
    print()
    
for _ in range(int(input())):
    main()