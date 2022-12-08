def isLowerCase(s):
    if s>='a' and s<='z':
        return True
    else:
        return False
n=input()
s=raw_input().strip()
st=set()
flag=0
maxx=0
count=0
for i in range(n):
    if flag==0:
        if isLowerCase(s[i]):
            if s[i] not in st:
                count+=1
                st.add(s[i])
        else:
            flag=1 
            if maxx<count:
                maxx=count
    else:
        if isLowerCase(s[i]):
            flag=0
            st=set([s[i]])
            count=1
if maxx<count:
    maxx=count
print(maxx)