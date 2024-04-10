import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    used = [False for _ in range(n)]
    ans = []
    for a in alst[::-1]:
        if not used[a - 1]:
            used[a - 1] = True
            ans.append(a)
    print(*ans[::-1])
            
for _ in range(int(input())):
    main()