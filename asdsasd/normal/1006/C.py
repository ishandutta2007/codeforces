import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    max_ = sum(A) // 2
    left = {0}
    tot = 0
    for a in A:
        tot += a
        if tot > max_:
            break
        left.add(tot)
    right = {0}
    tot = 0
    for a in A[::-1]:
        tot += a
        if tot > max_:
            break
        right.add(tot)
    print(max(left & right))
            
    
    
for _ in range(1):
    main()