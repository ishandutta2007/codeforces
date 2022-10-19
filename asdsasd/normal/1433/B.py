import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    flg = False
    ans = 0
    for i, a in enumerate(alst):
        if a == 1:
            if not flg:
                flg = True
            else:
                ans += i - bef - 1
            bef = i
        
    print(ans)
for _ in range(int(input())):
    main()