import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    A.sort()
    B.sort()
    for a, b in zip(A, B):
        if b - a not in [0, 1]:
            print("NO")
            return
    print("YES")
    
for _ in range(int(input())):
    main()