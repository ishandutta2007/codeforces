c = [720720, 720719, 720704, 720639, 720704, 720095, 719424, 718319, 720704, 720639, 710720, 706079, 719424, 692159, 682304, 670095, 720704]

n, m = map(int, input().split())
for i in range(n):
    a = list(map(int, input().split()))
    for j in range(m):
        if (i + j) % 2 == 0:
            print(c[0])
        else:
            print(c[a[j]])