b = [4,8,15,16,23,42]
n = int(input())
a = map(int, input().split())
cnt = [0] * 6
ans = 0
for x in a:
    i = b.index(x)
    if i == 0:
        cnt[0] += 1
    elif cnt[i-1] > 0:
        cnt[i-1] -= 1
        cnt[i] += 1
print(n-cnt[5] * 6)