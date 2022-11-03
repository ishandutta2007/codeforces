n = int(input())
a = []
summ = 0
for i in range(n):
    s = input()
    x = int(s[:-6])
    summ += x
    if s[-5:] == "00000":
        a.append([x, 0])
    else:
        if s[0] == '-':
            x -= 1
            summ -= 1
        a.append([x, 1])
i = 0
while i < n and summ != 0:
    if a[i][1]:
        a[i][0] += 1
        summ += 1
    i += 1
for i in range(n):
    print(a[i][0])