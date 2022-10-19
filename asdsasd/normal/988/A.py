import sys
input = sys.stdin.readline

def main():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    se = set(A)
    if len(se) < k:
        print("NO")
    else:
        print("YES")
        lst = []
        se = set()
        for i, a in enumerate(A):
            if a not in se:
                lst.append(i + 1)
                se.add(a)
                if len(lst) == k:
                    break
        print(*lst)
    
    
for _ in range(1):
    main()