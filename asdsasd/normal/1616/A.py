import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    cnt = {}
    for a in A:
        x = abs(a)
        cnt[x] = cnt.get(x, 0) + 1
    ans = 0
    for k, v in cnt.items():
        if k != 0:
            ans += min(v, 2)
        else:
            ans += min(v, 1)
    print(ans)
    
for _ in range(int(input())):
    main()