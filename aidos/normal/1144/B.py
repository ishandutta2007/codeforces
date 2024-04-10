n = int(input())
a = list(map(int, input().split()))
b = []
c = []
for i in a:
    if i % 2 == 0:
        b.append(i)
    else:
        c.append(i)
b = sorted(b)
c = sorted(c)
if len(b)==0 or len(c) == 0:
    print(sum(a) - max(a))
elif abs(len(b) - len(c)) <= 1:
    print(0)
elif len(c) > len(b):
    print(sum(c[:len(c) - len(b) - 1]))
else:
    print(sum(b[:len(b) - len(c)-1]))