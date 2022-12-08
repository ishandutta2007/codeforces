n, a, b, k, f = map(int,raw_input().split())
slov = dict()
temp = raw_input().split()
slov[frozenset(temp)] = a

for i in range(1, n):
    temp2 = raw_input().split()
    try:
        if temp2[0] == temp[1]:
            slov[frozenset(temp2)] += b
        else:
            slov[frozenset(temp2)] += a
    except KeyError:
        if temp2[0] == temp[1]:
            slov[frozenset(temp2)] = b
        else:
            slov[frozenset(temp2)] = a
    temp = temp2

costs = sorted(list(slov.values()), reverse=True)

for i in range(min(k, len(costs))):
    if costs[i] > f:
        costs[i] = f
    else:
        break
print(sum(costs))