import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    A.sort()
    print(A[-1] + A[-2])
    
for _ in range(int(input())):
    main()