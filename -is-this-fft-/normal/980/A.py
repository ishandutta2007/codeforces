necklace = input()

if necklace.count('o') == 0:
    print("YES")
elif necklace.count('-') % necklace.count('o') == 0:
    print("YES")
else:
    print("NO")