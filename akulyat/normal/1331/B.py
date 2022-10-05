n = int(input())
was = False
for i in range (2, 1000):
    if n % i == 0 and not was:
        print(i, n // i, sep = '')
        was = True