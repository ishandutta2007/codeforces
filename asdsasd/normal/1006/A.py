import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    print(*[a if a % 2 == 1 else a - 1 for a in A])
        
    
for _ in range(1):
    main()