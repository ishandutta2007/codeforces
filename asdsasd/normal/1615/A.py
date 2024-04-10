import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    if sum(A) % n == 0:
        print(0)
    else:
        print(1)
    
for _ in range(int(input())):
    main()