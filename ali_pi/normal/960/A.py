s=raw_input()
a=s.count('a')
b=s.count('b')
print(('NO','YES')[a*b and s in('a'*a+'b'*b+'c'*i for i in (a,b))])