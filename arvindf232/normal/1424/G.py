# 9 :24


def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

def ask(od):

    allData = []
    for a,b in od:
        allData.append((a,True))
        allData.append((b,False))

    allData = sorted(allData)

    maxL = 0
    maxYear = 0
    current = 0
    for num,b in allData:
        if(b):
            current += 1
        else:
            current -= 1

        if(current > maxL):
            maxL = current
            maxYear = num

    return maxYear, maxL

# import random

n = readInt()

ret = []
for _ in range(n):
    params = readLine()
    ret.append((params[0],params[1]))


# ret = []
#
# for _ in range(100000):
#     ret.append((random.randint(100000,1000000),random.randint(100000,1000000)))
#
# import time
#
# t0 = time.time()
a,b = ask(ret)
print(a,b)
# t1 = time.time()

# total = t1-t0
# print(total)