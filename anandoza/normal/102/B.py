n = raw_input()

answer = 0
while len(n) > 1:
  answer += 1
  n = str(sum(int(i) for i in n))

print answer