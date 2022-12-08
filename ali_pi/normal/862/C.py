import random
import sys
n,k=raw_input().split()
n=int(n)
k=int(k)
for tries in range(10000):
    a=random.sample(range(100001),n-1)
    x=0
    for i in a:
        x^=i
    if k^x not in a:
        print("YES")
        for i in a:
            print(i)
        print(k^x)
        sys.exit()
print("NO")