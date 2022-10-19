import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    lst = [0 for _ in range(101)]
    for a in alst:
        lst[a] += 1
    ans = 0
    flg = False
    for i, num in enumerate(lst):
        if num == 0:
            if not flg:
                ans = i * 2
            else:
                ans += i
            break
        elif num == 1 and not flg:
            ans += i
            flg = True
    print(ans)
    

for _ in range(int(input())):
    main()