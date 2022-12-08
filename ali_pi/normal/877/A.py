import re
s='Danil|Olya|Slava|Ann|Nikita'
print('YES' if len(re.findall(s,raw_input()))==1 else 'NO')