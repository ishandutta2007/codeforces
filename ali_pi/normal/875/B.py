n = input()
input_ = list(map(int, raw_input().split()))
pos = n
a = [0 for i in range(n+1)]
res = 1
ans = [1]
for x in input_:
    a[x] = 1
    res += 1
    while a[pos]==1:
        pos -= 1
        res -= 1
    ans.append(res)
print(' '.join(map(str, ans)))