import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    ans = 0
    for s in S:
        if ans == 0:
            ans = 1
        elif s == "B":
            ans -= 1
        else:
            ans += 1
    print(ans)

for _ in range(int(input())):
    main()