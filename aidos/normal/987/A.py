a = ["Power", "Time", "Space", "Soul", "Reality", "Mind"]
b = ["purple", "green", "blue", "orange", "red", "yellow"]
n = int(input())
c = []
for i in range(n):
    c.append(input())
ans = []
for i in range(6):
    if b[i] in c:
        continue
    ans.append(a[i])
print(len(ans))
for i in ans:
    print(i)