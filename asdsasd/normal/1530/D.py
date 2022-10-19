import sys
input = sys.stdin.readline

def main():
    n = int(input())
    alst = list(map(int, input().split()))
    print(len(set(alst)))
    
    lst = [[] for _ in range(n + 1)]
    ans = [-1] * n
    rem = set(range(1, n + 1))
    for i, a in enumerate(alst):
        if not lst[a]:
            ans[i] = a
            rem.remove(a)
        lst[a].append(i)
    rem = list(rem)
    for i, a in enumerate(alst):
        if ans[i] != -1:
            continue
        r = rem.pop()
        if r != i + 1:
            ans[i] = r
        else:
            p = lst[a][0]
            ans[i] = a
            ans[p] = r
    print(*ans)
            
        
    
    
    
            
for _ in range(int(input())):
    main()