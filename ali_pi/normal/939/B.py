N, K = map(int,raw_input().split())
l = map(int, raw_input().split())
g = [i*(N/i) for i in l]
m = max(g)
print((g.index(m))+1),( N/l[g.index(m)])