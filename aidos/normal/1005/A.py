n = int(input())
a = list(map(int, input().split()))
b = []

for i in a:
    if i == 1:
        b.append(1)
    else:
        b[-1]+=1
print(len(b))
for i in b:
    print(i, end = ' ')