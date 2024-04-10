import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    bef = S[0]
    cnt = 0
    for s in S[1:]:
        if bef == s:
            cnt += 1
        bef = s
    print((cnt + 1) // 2)
    
for _ in range(int(input())):
    main()