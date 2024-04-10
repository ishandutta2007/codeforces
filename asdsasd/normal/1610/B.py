import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    se = set()
    for i in range(n):
        if A[i] != A[n - i - 1]:
            se.add(A[i])
            se.add(A[n - i - 1])
            break
    if len(se) == 0:
        print("YES")
        return
    
    for s in se:
        B = []
        for a in A:
            if a != s:
                B.append(a)
        if B == B[::-1]:
            print("YES")
            return
    print("NO")
        
    
for _ in range(int(input())):
    main()