s = input()
x1 = ord(s[0]) - ord('a')
y1 = ord(s[1]) - ord('1')
s = input()
x2 = ord(s[0]) - ord('a')
y2 = ord(s[1]) - ord('1')

ans = 0

for i in range(8):
    for j in range(8):
        if i == x1 or j == y1:
            continue

        if i == x2 and j == y2:
            continue

        if abs(i - x1) == 1 and abs(j - y1) == 2 or abs(i - x1) == 2 and abs(j - y1) == 1:
            continue

        if abs(i - x2) == 1 and abs(j - y2) == 2 or abs(i - x2) == 2 and abs(j - y2) == 1:
            continue

        ans += 1


print(ans)