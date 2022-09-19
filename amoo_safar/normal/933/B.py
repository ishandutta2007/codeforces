p,k  = map(int,input().split())
num = [0] * 64
sum = 0
c = 0
power = k-1
while(sum < p):
    sum += power
    power *= k*k
    c += 2
#print(power / k / k << endl << sum << endl;
print(c-1)
i = 0
p = sum - p
while(p > 0):
    num[i] = p % k
    p //= k
    i += 1
#cout << sum << endl;
for i in range(c-1):
    #cout << num[i] << " ";
    if(i % 2 == 0) :print(k - 1 - num[i],end = ' ')
    else :print(num[i],end = ' ')