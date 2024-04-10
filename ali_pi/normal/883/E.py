n = int(raw_input())
s = str(raw_input())
m = int(raw_input())
cur = set(s)
st = None
for i in range(m):
    t = str(raw_input())
    #check first if t is possible
    ch = ''.join(i if i in s else '*' for i in t)
    if ch == s:
        if st is None:
            st = set(t)
        else:
            st.intersection_update(set(t))

if st is None:
    st = set()
st.difference_update(cur)
print len(st)