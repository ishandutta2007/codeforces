n, m = map(int, input().split())
a = list(input())
for i in range(m):
    l, r, c1, c2=input().split()
    for i in range(int(l)-1, int(r)):
        if a[i] == c1:
            a[i] = c2
print(''.join(a))