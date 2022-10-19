import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    ans = 0
    cnt = 0
    for s in S:
        if s == "x":
            cnt += 1
        else:
            ans += max(0, cnt - 2)
            cnt = 0
    ans += max(0, cnt - 2)
    print(ans)
    
    
for _ in range(1):
    main()