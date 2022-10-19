import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    suf = 0
    for s in S[::-1]:
        if s == ")":
            suf += 1
        else:
            break
    
    print("Yes" if suf * 2 > n else "No")
        
    
for _ in range(int(input())):
    main()