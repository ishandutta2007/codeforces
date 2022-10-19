n = int(input())
d = dict()
for el1 in "ABC":
    d[el1] = float('inf')
    for el2 in "ABC":
        d[el1 + el2] = float('inf')
        for el3 in "ABC":
            d[el1 + el2 + el3] = float('inf')
for i in range(n):
    a, b = input().split()
    a = int(a)
    b = list(b)
    b.sort()
    b = "".join(b)
    for i in range(len(b)):
        d[b[i]] = min(d[b[i]], a)
        for j in range(i + 1, len(b)):
            d[b[i] + b[j]] = min(d[b[i] + b[j]], a)
    d[b] = min(d[b], a)
for el1 in "ABC":
    for el2 in "ABC":
        if el2 >= el1:
            d[el1 + el2] = min(d[el1 + el2], d[el1] + d[el2])
for el1 in "ABC":
    for el2 in "ABC":
        if el2 >= el1:
            for el3 in "ABC":
                if el3 >= el2:
                    d[el1 + el2 + el3] = min(d[el1 + el2 + el3], d[el1 + el2] + d[el3], d[el1 + el3] + d[el2], d[el2 + el3] + d[el1])
print(d["ABC"] if d["ABC"] != float('inf') else -1)