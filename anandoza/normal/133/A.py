program = raw_input()

filtered = "".join(c for c in program if c in {"H", "Q", "9"})

print "YES" if filtered else "NO"