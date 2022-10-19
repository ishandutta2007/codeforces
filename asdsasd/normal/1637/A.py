import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    B = sorted(A)
    if A == B:
        print("NO")
    else:
        print("YES")
    
for _ in range(int(input())):
    main()