import re
n = input() ;s = raw_input()
s = re.sub('(RU|UR)', 'D', s)
a = len(s)
print(a)