import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    bef = 0
    flg = False
    ans = n
    for a in alst[::-1]:
        if not flg:
            if a < bef:
                flg = True
            ans -= 1
        else:
            if a > bef:
                break
            ans -= 1
        bef = a
    print(ans)
            
        
        
for _ in range(int(input())):
    main()