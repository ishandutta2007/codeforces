n = int(input())
s = input()
t = 'ACTG'
ans = 10**6
for i in range(n-3):
    x = s[i:i+4]
    cur = 0
    for j in range(4):
        dis = abs(ord(x[j]) - ord(t[j]))
        cur += min(dis, 26-dis)
    ans = min(ans, cur)
print(ans)