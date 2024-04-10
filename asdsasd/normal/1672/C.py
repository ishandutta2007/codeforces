import sys
input = sys.stdin.readline

def main():
    n = int(input())    
    A = list(map(int, input().split()))
    l = -1
    for i in range(1, n):
        if A[i] == A[i - 1]:
            l = i + 1
            break
    if l == -1:
        print(0)
        return
    for i in range(n - 1, -1, -1):
        if A[i] == A[i - 1]:
            r = i
            break
    if l > r:
        print(0)
    elif l == r:
        print(1)
    else:
        print(r - l)
        
    
        
        
    
for _ in range(int(input())):
    main()