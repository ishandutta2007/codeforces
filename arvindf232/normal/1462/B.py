def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

import re

def FIRST_FALSE(range,function,allTrue):
    for i in range:
        if(function(i)):
            continue
        else:
            return i

    return allTrue


def ask(str):
    text = "2020"

    if (len(str) < 4):
        return False
    found = FIRST_FALSE(range(4), lambda y: str[y] == text[y], len(text))



    if(found == 4):
        return True

    requiring = text[found:]
    remaining = str[found:]


    if(re.search(requiring + "$",remaining)):
        return True
    else:
        return False




t = readInt()
for i in range(t):
    n = readInt()
    str = readString()

    if ask(str):
        print("YES")
    else:
        print("NO")