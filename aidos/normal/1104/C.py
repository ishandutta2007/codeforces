s = input()
has1 = 0
has2 = 0
for x in s:
    if x == '0':
        if has1 == 0:
            has1 = 1
            print(1, 1)
        else:
            has1 = 0
            print(3, 1)
    else:
        if has2 == 0:
            has2 = 1
            print(4, 3)
        else:
            has2 = 0
            print(4, 1)