import sys
input = sys.stdin.readline

def main():
    k, r = map(int, input().split())
    if k % 10 == 0:
        print(1)
        return
    cnt = 1
    ans = k
    while ans % 10 != r and ans % 10 != 0:
        ans += k
        cnt += 1
    print(cnt)


main()
"""
for _ in range(int(input())):
    main()
"""