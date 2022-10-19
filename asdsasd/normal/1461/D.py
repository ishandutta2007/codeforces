import sys
input = sys.stdin.readline
from bisect import bisect_right, bisect_left
sys.setrecursionlimit(10 ** 9)

def main():
    n, q = map(int, input().split())
    alst = list(map(int, input().split()))
    alst.sort()
    se = set()
    cum = [0]
    for a in alst:cum.append(cum[-1] + a)
    
    def dfs(l, r, c = 0):
        se.add(cum[r + 1] - cum[l])
        if alst[l] == alst[r] or l >= r: return
        mid = (alst[l] + alst[r]) // 2
        pos_r = bisect_right(alst, mid)
        pos_l = bisect_left(alst, mid)
        dfs(l, pos_r - 1, c + 1)
        dfs(pos_r, r, c + 1)
    
    dfs(0, n - 1)
    for _ in range(q):
        if int(input()) in se:
            print("Yes")
        else:
            print("No")
        
    
for _ in range(int(input())):
    main()