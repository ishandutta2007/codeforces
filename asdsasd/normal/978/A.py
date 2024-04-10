import sys
input = sys.stdin.readline

def main():
    n = int(input())
    A = list(map(int, input().split()))
    se = set()
    ans = []
    for a in A[::-1]:
        if a not in se:
            ans.append(a)
            se.add(a)
    print(len(ans))
    print(*ans[::-1])
    
    
    
for _ in range(1):
    main()