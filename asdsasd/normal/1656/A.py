import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A =list(map(int, input().split()))
    print(A.index(min(A)) + 1, A.index(max(A)) + 1)
    
for _ in range(int(input())):
    main()