s=raw_input()
t=''.join(c for c in s if c!='1')
i=(t+'2').find('2')
print(t[:i]+s.count('1')*'1'+t[i:])