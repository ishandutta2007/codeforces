import sys
input = sys.stdin.readline

class Node:
    def __init__(self, i):
        self.i = i
        self.nex = None
        self.bef = None

def solve():
    n = int(input())
    P = list(map(int, input().split()))
    node = [Node(i) for i in range(n)]
    for i, p in enumerate(P):
        p -= 1
        node[p].nex = node[i]
        node[i].bef = node[p]
    used = [False] * n
    V = node[0]
    while not used[V.i]:
        used[V.i] = True
        V = V.nex
    for i in range(n):
        if used[i]:
            continue
        V = node[i]
        while not used[V.i]:
            used[V.i] = True
            V = V.nex
        """
        node[i].nex = node[i - 1].nex
        node[i - 1].nex = node[i].nex
        node[i].nex.bef = node[i - 1]
        node[i - 1].nex.bef = node[i]
        """
        node[i].nex, node[i - 1].nex, node[i].nex.bef, node[i - 1].nex.bef = node[i - 1].nex, node[i].nex, node[i - 1], node[i]

    ans = [1]
    V = node[0].nex
    while V.i != 0:
        ans.append(V.i + 1)
        V = V.nex
    print(*ans)

for _ in range(int(input())):
    solve()