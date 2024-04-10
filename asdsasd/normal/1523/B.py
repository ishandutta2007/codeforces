import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    print(6 * n // 2)
    for i in range(1, n + 1, 2):
        j = i + 1
        print(1, i, j)
        print(2, i, j)
        print(1, i, j)
        print(1, i, j)
        print(2, i, j)
        print(1, i, j)
        
    
for _ in range(int(input())):
    main()