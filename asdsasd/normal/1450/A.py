import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = list(input().strip())
    S.sort()
    print("".join(S))
    
for _ in range(int(input())):
    main()