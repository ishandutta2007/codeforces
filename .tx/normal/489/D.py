import sys

def inp():
    return sys.stdin.readline().rstrip()

def main():
    n, m = map(int, inp().split(' '))
    g = [[] for _ in range(n)]
    for i in range(m):
        a, b = map(int, inp().split(' '))
        g[a - 1].append(b - 1)
        
    ans = 0
    for v in range(n):
        c = [0] * n
        for t in g[v]:
            for u in g[t]:
                c[u] += 1
                
        c[v] = 0
        for x in c:
            ans += x * (x - 1) // 2
            
    print(ans)
    
    
main()