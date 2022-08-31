n = int(input())
l = list(input())
if(n > 3):
    ct = n//2 - 1
    ind = 2
    for i in range(ct):
        l.insert(ind,'-')
        ind += 3
for i in l:
    print(i,end = "")
print()