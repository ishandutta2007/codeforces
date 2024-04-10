n = int(input())
x = list(input())
for i in range(1, n+1):
    if n % i == 0:
        x[:i] = x[i-1::-1]
print(''.join(x))