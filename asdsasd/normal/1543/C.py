import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 9)

def main():
    c, m, p, v = map(float, input().split())
    eps = 10 ** -9
    def dfs(cnt, x, c, m, p):
        cnt += 1
        ret = 0
        ret = x * p * cnt
        if c != 0:
            if c < v + eps:
                if m == 0:
                    ret += dfs(cnt, x * c, 0, 0, 1)
                else:
                    ret += dfs(cnt, x * c, 0, m + c / 2, p + c / 2)
            else:
                if m == 0:
                    ret += dfs(cnt, x * c, c - v, 0, p + v)
                else:
                    ret += dfs(cnt, x * c, c - v, m + v / 2, p + v / 2)
        if m != 0:
            if m < v + eps:
                if c == 0:
                    ret += dfs(cnt, x * m, 0, 0, 1)
                else:
                    ret += dfs(cnt, x * m, c + m / 2, 0, p + m / 2)
            else:
                if c == 0:
                    ret += dfs(cnt, x * m, 0, m - v, p + v)
                else:
                    ret += dfs(cnt, x * m, c + v / 2, m - v, p + v / 2)
        return ret
        
    print(dfs(0, 1, c, m, p))
    
    
for _ in range(int(input())):
    main()