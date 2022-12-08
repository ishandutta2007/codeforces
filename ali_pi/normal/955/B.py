s=raw_input()
t=set(s)
l=len(t)
print(['No','Yes'][1<l<5and l+sum(s.count(x)>1for x in t)>3])