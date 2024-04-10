n = int(input())
a = list(map(int, input().split()))
s = sum(a)
x = 0
for i in range(n):
    x += a[i]
    if x * 2 >= s:
        print(i+1)
        break