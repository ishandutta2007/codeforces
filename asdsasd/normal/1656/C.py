import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    A = sorted(set(A))
    if len(A) == 1:
        print("YES")
        return
    if 1 not in A:
        print("YES")
        return
    
    for i in range(1, len(A)):
        if A[i] == A[i - 1] + 1:
            print("NO")
            return
    print("YES")
        
    
    
for _ in range(int(input())):
    main()