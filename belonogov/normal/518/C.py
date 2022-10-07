n, m, k = map(int, input().split()) 
a = list(map(int, input().split()))
b = list(map(int, input().split()))

perm = [-1] * n

for i in range(0, n):
    a[i] -= 1;
    perm[a[i]] = i

ans = 0;
for x in b:
    x -= 1;
    pos = perm[x];
    ans += pos // k + 1;
    if pos != 0:
        val = a[pos - 1]
        a[pos - 1], a[pos] = a[pos], a[pos - 1]
        perm[x], perm[val] = perm[val], perm[x]     

print(ans);