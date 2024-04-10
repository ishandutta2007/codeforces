def solve():
    s=input()
    s=sorted(s)
    kol=[0]*26
    for i in s:
        kol[ord(i)-ord('a')]+=1
    st=set()
    for i in s:
        st.add(ord(i)-ord('a'))
    v=list(st)
    v=sorted(v)
    if viv:
        print("Sorted", v)
    n=len(v)
    v2=list()
    for i in range(1, n, 2):
        v2.append(v[i])
    for i in range(0, n, 2):
        v2.append(v[i])
    if len(v2)==3:
        if v[0]+1==v[1]:
            v2=[v[0], v[2], v[1]]
        else:
            v2=[v[1], v[0], v[2]]
    if viv:
        print("Look at it:", v2)
    ans=""
    for i in v2:
        ans+=((""+chr(ord('a')+i))*kol[i])
    for i in range(len(ans)-1):
        if abs(ord(ans[i])-ord(ans[i+1]))==1:
            print("No answer")
            return
    print(ans)



viv=False
#viv=True
t=int(input())
while (t):
    solve()
    t-=1