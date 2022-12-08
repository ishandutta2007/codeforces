import re
raw_input()
print(re.sub(r'(?<=[aeiouy])[aeiouy]+', '', raw_input()))