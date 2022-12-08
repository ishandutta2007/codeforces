n, k = map(int, raw_input().split(' '))
p = list(map(int, raw_input().split(' ')))
i = 0
s = []
cur = 1
solution = list(p)
while True:
    if len(s) > 0 and s[-1] == cur:
        cur += 1
        s.pop()
    elif i < len(p):
        if len(s) > 0 and p[i] > s[-1]:
            solution = [-1]
            break
        s.append(p[i])
        i += 1
    else:
        break
if solution[0] != -1:
    while cur <= n:
        top = s.pop() if len(s) > 0 else n + 1
        solution.extend(reversed(range(cur, top)))
        cur = top + 1
print(' '.join(str(x) for x in solution))