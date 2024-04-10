n = int(input())
a = list(map(int, input().split()))
b = [0] * 2020

for i in a:
    b[i] += 1

for i in range(2010, 0, -1):
    b[i] += b[i+1]

for i in a:
    print(b[i+1] + 1, end = ' ')