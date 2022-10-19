n, v = list(map(int, input().split()))
cost = 0
cur_v = 0
for i in range(1, n + 1):
    rem = n - i
    if cur_v > rem:
        break
    elif rem <= v:
        cost += i * (rem - cur_v)
        cur_v = rem
    else:
        cost += i * (v - cur_v)
        cur_v = v
    cur_v -= 1

print(cost)