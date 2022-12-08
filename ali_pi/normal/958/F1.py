n, m = map(int,raw_input().split())
c = list(map(int,raw_input().split()))
k = list(map(int,raw_input().split()))
s = sum(k)
for i in range(n-s+1):
    v = [0] * m
    for j in range(i, i+s):
        v[c[j]-1]+=1
    if v == k:
        print('YES')
        exit(0)
print('NO')