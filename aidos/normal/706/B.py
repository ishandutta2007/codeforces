n = int(input())
a = [0] * 100100
b = map(int, input().split())
for x in b:
    a[x]+=1
q = int(input())
for j in range(1, 100100):
    a[j] += a[j-1]

for _ in range(q):
    h = min(100000, int(input()))
    print(a[h])