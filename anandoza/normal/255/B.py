s = raw_input()

x = s.count("x")
y = s.count("y")

if x > y:
  print "".join("x" for i in range(x-y))
else:
  print "".join("y" for i in range(y-x))