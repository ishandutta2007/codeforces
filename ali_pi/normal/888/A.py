raw_input()
l=list(map(int,raw_input().split()))
a=0
for i in range(1,len(l)-1):
    if (l[i]-l[i-1])*(l[i]-l[i+1])>0:
        a+=1
print(a)