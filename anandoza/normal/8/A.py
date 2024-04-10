flags = raw_input()
first = raw_input()
second = raw_input()

def findable(a, b, c):
  i = a.rfind(c)
  return (i != -1) and (b in a[:i])

forward = findable(flags, first, second)
backward = findable(flags[::-1], first, second)

if forward and backward:
  print "both"
elif forward:
  print "forward"
elif backward:
  print "backward"
else:
  print "fantasy"