l, r = map(int, input().split())
n = (r-l+1)//2
print('YES')
for i in range(n):
    print(l + 2*i, l + 2 * i + 1)