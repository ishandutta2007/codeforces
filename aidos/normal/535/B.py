n = int(input())
x = []
while n > 0:
    if n % 10 == 4:
        x = [0] + x
    else:
        x = [1] + x
    n //= 10
cur = 0
for i in x:
    cur = cur * 2 + i

for i in range(1, len(x)):
    cur += 2 ** i
print(cur + 1)