n,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
oa = ea = ob = eb = 0
for i in a:
    if(i%2 == 0):
        oa += 1
    else:
        ea += 1

for i in b:
    if(i%2 == 0):
        ob += 1
    else:
        eb += 1

print(min(oa,eb) + min(ea,ob))