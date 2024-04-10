line1 = input()

s = input()
t = input()

if s.find('*') == -1:
    if s == t:
        print("YES")
    else:
        print("NO")
else:
    splitat = s.find('*')
    pref = s[:splitat]
    suff = s[splitat+1:]
    
    if (pref == t[:len(pref)]) and (suff == t[-len(suff):]) and len(pref) + len(suff) <= len(t):
        print("YES")
    elif pref == t[:len(pref)] and len(suff) == 0 and len(pref) + len(suff) <= len(t):
        print("YES")
    else:
        print("NO")