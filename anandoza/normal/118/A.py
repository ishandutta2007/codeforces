word = raw_input()
word = word.lower()

answer = ""

for char in word:
  if char not in ("a", "e", "i", "o", "u", "y"):
    answer += "." + char

print answer