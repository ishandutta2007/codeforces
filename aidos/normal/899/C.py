n = int(input())
x = n * (n+1)//2
a = x//2
b = x - a
c = []
print(abs(b-a))
for i in range(n, 0, -1):
    if i <= a:
        a-=i
        c.append(i)
print(len(c), end = ' ')
for i in c:
    print(i, end = ' ')