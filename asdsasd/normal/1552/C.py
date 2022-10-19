import sys
input = sys.stdin.readline


def main():
    n, k = map(int, input().split())
    used = set(range(1, 2 * n + 1))
    edges = []
    for _ in range(k):
        x, y = map(int, input().split())
        edges.append((x, y))
        used.remove(x)
        used.remove(y)
    lst = list(sorted(used))
    l = len(lst)
    for i in range(l // 2):
        edges.append((lst[i], lst[l // 2 + i]))
    ans = 0
    for i in range(n):
        r1, l1 = edges[i]
        for j in range(i + 1, n):
            r2, l2 = edges[j]
            so = sorted([(r1, 1), (l1, 1), (r2, 2), (l2, 2)])
            if so[0][1] == so[2][1]: ans += 1
    print(ans)
            
        
for _ in range(int(input())):
    main()