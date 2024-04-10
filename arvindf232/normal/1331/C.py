
# 6 to 6
# 5 to 1
# 3 to 4
# 4 to 3
# 2 to 2
# 5 to 1

def readInt():
    return int(input())

z = readInt()

def redBinary(x):
    powers = []
    i = 1
    while i <= x:
        if i & x:
            powers.append(i)
        i <<= 1
    return powers

def swap(x):
    if x is 1:
        return 16
    elif x is 16:
        return 1
    elif x is 4:
        return 8
    elif x is 8:
        return 4
    else:
        return x

ze = [swap(x) for x in redBinary(z)]
print(sum(ze))