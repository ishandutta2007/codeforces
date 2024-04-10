n = int(input())
arr = list(map(int, input().split()))
d = dict()
for el in arr:
    d[el] = d.get(el, 0) + 1
min_ans = 0
for el1 in d:
    for el2 in d:
        if el1 != el2:
            for x in range(2, 101):
                if el1 % x == 0:
                    min_ans = min(min_ans, el1 // x + el2 * x - el1 - el2)
print(sum(arr) + min_ans)