import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    bef = 1 << 60
    ans = 0
    for a in A[::-1]:
        if bef == 0:
            print(-1)
            return
        while a >= bef:
            a //= 2
            ans += 1
        bef = a
    print(ans)
    
for _ in range(int(input())):
    main()