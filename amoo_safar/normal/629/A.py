n = int(input())
a = []
t = 0
for i in range(n):
    a.append(list(input()))
    x = a[-1].count('C')
    t +=((x*(x-1)//2))
for i in zip(*a):
    x = list(i).count('C')
    t +=((x*(x-1)//2))
print(t)