import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = list(input().strip())
    T = sorted(S)
    print(sum(s != t for s, t in zip(S, T)))
    
for _ in range(int(input())):
    main()