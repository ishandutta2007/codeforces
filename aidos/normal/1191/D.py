n = int(input())
a = sorted(map(int, input().split()))
ind = 0
s = sum(a) - n * (n-1)//2
for i in range(n):
    if a[i] == a[i-1]:
        ind = i
    elif ind == 0 and a[i] > a[i-1] + 1:
        ind = i

a[ind] -= 1
a = sorted(a)
b = set(a)
if min(a) < 0 or len(b) != n or s % 2 != 1:
    print('cslnb')
else:
    print('sjfnb')