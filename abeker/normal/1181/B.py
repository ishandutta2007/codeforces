l = int(input())
n = input()

cands = []
for i in range(0, l - 1):
  if n[i + 1] != '0':
    cands.append((max(i + 1, l - i - 1), i))

cands.sort()

ans = -1
for i in range(0, min(4, len(cands))):
  mx, idx = cands[i]
  tmp = int(n[0:idx + 1]) + int(n[idx + 1:l])
  if ans == -1 or tmp < ans:
    ans = tmp

print(ans)