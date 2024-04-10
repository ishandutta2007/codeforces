import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    print(max(A) - min(A))
    
for _ in range(int(input())):
    main()