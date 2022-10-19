import sys
input = sys.stdin.readline

def main():
    S = list(map(int, input().strip()))
    if sum(S[:3]) == sum(S[3:]):
        print("YES")
    else:
        print("NO")

for _ in range(int(input())):
    main()