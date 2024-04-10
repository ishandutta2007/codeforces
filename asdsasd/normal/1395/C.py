import sys
input = sys.stdin.buffer.readline

def main():
    n, m = map(int, input().split())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    clst = [[] for _ in range(n)]
    for i, a in enumerate(alst):
        for b in blst:
            clst[i].append(a & b)
    ans = set(clst[0])
    for lst in clst[1:]:
        ans2 = set()
        for num in ans:
            for num2 in lst:
                ans2.add(num | num2)
        ans = ans2.copy()
    print(min(ans))
    
    
    
            
    
"""
t = int(input())    
for _ in range(t):
    main()
"""
main()