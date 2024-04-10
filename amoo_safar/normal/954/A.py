n = int(input())
a = input()
o = ''
i=0
while i < n-1:
    #print(i)
    if a[i] != a[i+1]:
        i+=1
        o += 'D'
    i+=1
print(n-len(o))