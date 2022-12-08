input()
a = b = 0
for q in list(map(int,input().split()))[::-1]:
    if b > a + q: a += q
    else: b, a = a + q, b
print(a, b)