from collections import Counter

word = raw_input()
k = int(raw_input())

count = Counter(word)
to_delete = set()
for c, m in count.most_common()[::-1]:
  if k - m >= 0:
    to_delete.add(c)
    k -= m
  else:
    break

answer = "".join(c for c in word if c not in to_delete)
m = len(set(c for c in answer))
print m
print answer