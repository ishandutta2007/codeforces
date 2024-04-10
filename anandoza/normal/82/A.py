n = int(raw_input())
names = ("Sheldon", "Leonard", "Penny", "Rajesh", "Howard")
next_name = dict()
for i in range(5):
  next_name[names[i]] = names[(i+1) % 5]
prev_name = dict()
for i in range(5):
  prev_name[names[(i+1) % 5]] = names[i]

name = "Sheldon"
i = 0
k = 1
while i < n:
  i += k
  name = next_name[name]
  if name == "Sheldon":
    k *= 2

print prev_name[name]