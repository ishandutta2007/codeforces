import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    print(sum(A) - min(A) * n)

for _ in range(int(input())):
    main()