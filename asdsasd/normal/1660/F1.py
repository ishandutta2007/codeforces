import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    ans = 0
    for i in range(n):
        p = 0
        m = 0
        for j in range(i, n):
            if S[j] == "+":
                p += 1
            else:
                m += 1
            if m >= p and (m - p) % 3 == 0:
                ans += 1
    print(ans)
        
            
    
    
for _ in range(int(input())):
    main()