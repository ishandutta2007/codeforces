n = int(input())
q = []
w= []
for i in range(n):
    r = list(map(int ,input().split()))
    q += [r[0]]
    w += [r[1]]
for i in range(n):
    print(w[i]*2)