x = int(input())
a = [pow(2,i)-1 for i in range(22)]
i = 0
#print(a)
b = []
while(x not in a):
    #print("out : " ,x)
    if(i % 2 == 0):
        for j in range(22):
            if(a[j] > x):
                x = x^a[j]
                #print(x,a[j])
                b.append(j)
                break
    else:
        x += 1
    i += 1
print(i)
for j in b:
    print(j,end = " ")