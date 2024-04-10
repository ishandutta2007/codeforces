import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    se = set(A)
    for a in A:
        if a - k in se:
            print("YES")
            return
    print("NO")
    
for _ in range(int(input())):
    main()