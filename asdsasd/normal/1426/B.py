import sys
input = sys.stdin.readline

def main():
    n, m = map(int, input().split())
    lst = [[list(map(int, input().split())) for _ in range(2)] for _ in range(n)]
    if m % 2 == 1:
        print("NO")
        return
    for blk in lst:
        if blk[0][1] == blk[1][0]:
            print("YES")
            return
    print("NO")
    
    
for _ in range(int(input())):
    main()