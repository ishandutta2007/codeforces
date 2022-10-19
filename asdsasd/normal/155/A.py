import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    max_ = alst[0]
    min_ = alst[0]
    ans = 0
    for a in alst[1:]:
        if a > max_:
            max_ = a
            ans += 1
        elif a < min_:
            min_ = a
            ans += 1
    print(ans)

main()
"""
for _ in range(int(input())):
    main()
"""