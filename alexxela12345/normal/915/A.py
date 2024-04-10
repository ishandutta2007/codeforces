n, k = list(map(int, input().split()))
arr = list(map(int, input().split()))
m = 0
for el in arr:
    if k % el == 0 and el > m:
        m = el
print(k // m)