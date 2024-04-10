a= [0] * 4
raw_input()
for n in map(int,raw_input().split()):
  if n == 1:
    a[0] += 1
    a[2] = max(a[1] + 1, a[2] + 1)
  else:
    a[1] = max(a[0] + 1, a[1] + 1)
    a[3] = max(a[2] + 1, a[3] + 1)
print(max(a))