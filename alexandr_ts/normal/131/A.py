s = raw_input()
print s.swapcase() if all([c.isupper() for c in s[1:]]) else s