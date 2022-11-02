n = int(input())
k = 5
while k * k <= n and n % k != 0:
    k += 1
s = 'aeiou'
if k * k <= n and n % k == 0:
    for i in range(n//k):
        for j in range(k):
            print(s[(i+j)%5], end='')
        
else:
    print("-1")