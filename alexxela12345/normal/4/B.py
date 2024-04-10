d, sum_time = list(map(int, input().split()))
t = [list(map(int, input().split())) for i in range(d)]
schedule = [0 for i in range(d)]
s = 0
for i in range(d):
    s += t[i][0]
    schedule[i] = t[i][0]
    t[i][0] = t[i][1] - t[i][0]
if s > sum_time:
    print("NO")
else:
    for i in range(d):
        while s != sum_time and t[i][0] > 0:
            schedule[i] += 1
            s += 1
            t[i][0] -= 1
    if s == sum_time:
        print("YES")
        print(*schedule)
    else:
        print("NO")