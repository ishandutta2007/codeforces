import sys
input = sys.stdin.readline

def main():
    n = int(input())
    xlst = list(map(int, input().split()))
    ans = 0
    bef = -1
    for i in range(n):
        if xlst[i] < bef:
            xlst[i] += 1
        elif xlst[i] == bef:
            xlst[i] += 1
            ans += 1
        else:
            ans += 1
        bef = xlst[i]
    print(ans)
    
    
for _ in range(int(input())):
    main()