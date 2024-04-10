import sys
input = sys.stdin.readline

def main():
    n = int(input())
    S = input()
    for i in range(2, n + 1):
        if n % i == 0:
            S = S[:i][::-1] + S[i:]
    print(S)
    
    
for _ in range(1):
    main()