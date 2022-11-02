a = input()
cnt = 0
for i in a:
    if i in "aeiou":
        cnt += 1
    elif ord(i) >= ord('0') and ord(i) <= ord('9'):
        cnt += int(i) % 2
print(cnt)