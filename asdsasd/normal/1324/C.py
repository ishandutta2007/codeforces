import sys
input = sys.stdin.readline

def main():
    S = input().strip()
    ans = 1
    cnt = 0
    for s in S:
        if s == "L":
            cnt += 1
            ans = max(ans, cnt + 1)
        else:
            cnt = 0
    print(ans)
    
for _ in range(int(input())):
    main()