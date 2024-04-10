hola=input()
a= input()
ho=0
for i in range(1, (len(a)+2)//2):
    if(a[0:i] == a[i:2*i]):
        ho=i
if(ho!=0):
    print(len(a)-ho+1)
else:
    print(len(a))