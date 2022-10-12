line = raw_input()
tokens = line.split("0") + line.split("1")
print "YES" if any(len(x) >= 7 for x in tokens) else "NO"