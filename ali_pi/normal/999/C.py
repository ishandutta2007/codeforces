n, k = map(int,raw_input().split())
col = list(raw_input())
v = sorted((x, index) for index, x in enumerate(col))
for i in range(k):
    col[v[i][1]] = ''
print(''.join(col))