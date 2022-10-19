import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    time = 240 - k
    ans = -1
    cnt = 1
    while time >= 0:
        ans += 1
        time -= cnt * 5
        cnt += 1
    print(min(ans, n))

main()
"""
for _ in range(int(input())):
    main()
"""