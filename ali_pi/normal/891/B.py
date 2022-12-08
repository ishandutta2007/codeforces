n=input()
a=list(map(int,raw_input().split()))
b = sorted(a) + [min(a)]
for i in range(n):print(b[b.index(a[i])+1]);end=' '