n = int(input())
a = input()
o = ''
m = 0
for i in range(n//2):
    #print(a[:i+1],a[i+1:i+i+2])
    if a[:i+1] == a[i+1:i+i+2]:
     #   print(a[:i+1])
        m = i
print(n-m)