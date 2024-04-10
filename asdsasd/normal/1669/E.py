import sys
input = sys.stdin.readline

def main():
    n = int(input())
    a = [0] * 26
    b = [0] * 26
    ab = [0] * (26 * 26)
    for _ in range(n):
        S = input().strip()
        p1 = ord(S[0]) - 97
        p2 = ord(S[1]) - 97
        a[p1] += 1
        b[p2] += 1
        ab[p1 * 26 + p2] += 1
    ans = 0
    for c in a:
        ans += c * (c - 1) // 2
    for c in b:
        ans += c * (c - 1) // 2
    for c in ab:
        ans -= c * (c - 1)
    print(ans)
    
    
for _ in range(int(input())):
    main()