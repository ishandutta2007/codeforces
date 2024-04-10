s=raw_input()
print(('No','Yes')[any(set(x)==set('ABC')for x in zip(s,s[1:],s[2:]))])