import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input().strip()
    for i in range(5):
        if S[:i] + S[n - 4 + i:] == "2020":
            print("YES")
            return
    print("NO")
    
    
for _ in range(int(input())):
    main()