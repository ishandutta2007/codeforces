n = int(input())
res = ''
_n = n
for i in range(2, _n):
    while n % i == 0:
        res = res + str(i)
        n = n / i
print res