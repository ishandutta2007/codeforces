import sys
input = sys.stdin.readline

def main():
    n = int(input())
    dlst = list(map(int, input().split()))
    dlst.sort()
    ans = dlst[-1]
    tot = 0
    for i, d in enumerate(dlst[1:], 1):
        ans -= d * i - tot
        tot += d
    print(ans)

for _ in range(int(input())):
    main()