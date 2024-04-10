import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    mi = sum(a < 0 for a in A)
    B = []
    for i, a in enumerate(A):
        if i < mi:
            B.append(-abs(a))
        else:
            B.append(abs(a))
    if B == sorted(B):
        print("YES")
    else:
        print("NO")
    
    
for _ in range(int(input())):
    main()