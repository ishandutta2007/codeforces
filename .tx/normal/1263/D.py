from sqlite3 import connect
import sys

def inp():
    return sys.stdin.readline().rstrip()

def main():
    n = int(inp())
    a = [inp() for _ in range(n)]
    n = len(a)
    alphabet = dict()
    for s in a:
        for c in s:
            if c not in alphabet:
                alphabet[c] = len(alphabet)
    m = len(alphabet)
    g = [[] for _ in range(n + m)]
    for i in range(n):
        connected = set()
        for c in a[i]:
            connected.add(alphabet[c])
        for j in connected:
            g[i].append(n + j)
            g[n + j].append(i)
    used = [False] * (n + m)
    ans = 0
    for i in range(n):
        if not used[i]:
            ans += 1
            q = [i]
            used[i] = True
            iq = 0
            while iq < len(q):
                v = q[iq]
                iq += 1
                for u in g[v]:
                    if not used[u]:
                        used[u] = True
                        q.append(u)
                        
    print(ans)
            
    
main()