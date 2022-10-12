n = int(raw_input())

for iteration in range(n):
  word = raw_input()
  if len(word) > 10:
    word = word[0] + str(len(word)-2) + word[len(word)-1]
  print word