s , k = input().split()
n = int(input())

print(s , k)
for i in range(n):
    t , m = input().split()
    if(t == s):
        s = m
    else:
        k = m
    print(s , k)