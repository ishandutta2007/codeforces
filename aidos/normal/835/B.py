k = int(input())
n = sorted(input())
for g in n:
    g = int(g)
    k -= g
cnt = 0
for g in n:
    if k <= 0:
        continue
    k += int(g)
    k -= 9
    cnt += 1
print(cnt)