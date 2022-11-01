k = int(raw_input())
l = int(raw_input())
m = int(raw_input())
n = int(raw_input())
d = int(raw_input())
a = [0]*d
for i in range(d):
    if (i+1) % k == 0:
        a[i]=1
    if (i+1) % l == 0:
        a[i]=1        
    if (i+1) % m == 0:
        a[i]=1   
    if (i+1) % n == 0:
        a[i]=1  
print(sum(a))