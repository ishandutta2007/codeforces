w, h = [int(i) for i in input().split()]
a = []
for i in range(h):
    a.append([])
    a[i] = [q for q in input().strip()]
for i in range(w):
    now_str = ''
    for q in range(h):
        now_str += a[q][i] * 2
    print(now_str)
    print(now_str)