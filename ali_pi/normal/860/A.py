vow = ['a', 'e', 'i', 'o', 'u']
str = raw_input()
i = 0
while True:
    if i + 3 > len(str):
        break
    found = True
    for j in range(i, i + 3):
        if str[j] in vow:
            found = False
            break
    if found:
        if str[i] != str[i + 1] or str[i] != str[i + 2]:
            str = str[0:i + 2] + ' ' + str[i + 2:]
            i = i + 3
            continue
    i += 1
print(str)