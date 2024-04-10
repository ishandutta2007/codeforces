n, k = map(int, raw_input().split())
i = 1
while i <= k:
    if n % i != i - 1:
        print ("No")
        exit()
    i += 1
print ("Yes")