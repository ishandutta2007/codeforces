import sys

def inp():
    return sys.stdin.readline().rstrip()

def main():
    n = int(inp())
    g = [[] for _ in range(2 * n)]
    pairs = [(0, 0)] * n
    for i in range(n):
        a, b = map(int, inp().split(' '))
        pairs[i] = (a - 1, b - 1)
    for p in pairs:
        g[p[0]].append(p[1])
        g[p[1]].append(p[0])
    for i in range(n):
        g[i * 2].append(i * 2 + 1)
        g[i * 2 + 1].append(i * 2)
        
    color = [0] * (2 * n)
    def bfs(i):
        q1, q2 = [i], []
        while q1:
            for v in q1:
                for u in g[v]:
                    if color[u] == 0:
                        color[u] = 3 - color[v]
                        q2.append(u)
            q1.clear()
            q1, q2 = q2, q1
    for i in range(2 * n):
        if color[i] == 0:
            color[i] = 1
            bfs(i)
    
    for p in pairs:
        sys.stdout.write(str(color[p[0]]))
        sys.stdout.write(' ')
        sys.stdout.write(str(color[p[1]]))
        sys.stdout.write('\n')
        
    sys.stdout.flush()
    
main()