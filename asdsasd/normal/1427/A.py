import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    total = sum(alst)
    if total == 0:
        print("NO")
        return
    print("YES")
    alst.sort()
    if total > 0:
        print(*alst[::-1])
    else:
        print(*alst)
    
for _ in range(int(input())):
    main()