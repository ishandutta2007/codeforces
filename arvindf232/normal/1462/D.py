def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()




from functools import reduce

def factors(n):
    return sorted(reduce(list.__add__,
                      ([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0)))

def RIGHTMOST_TRUE(range, function, noneTrue):
    for i in reversed(range):
        if (function(i)):
            return i
        else:
            continue

    return noneTrue

def FIRST_TRUE(range,function,noneTrue):
    for i in range:
        if (function(i)):
            return i
        else:
            continue

    return noneTrue


def ask(s):


    total = sum(s)
    testingP = factors(total)
    # print(testingP)

    def testTrue(split):
        accum = 0
        for x in s:
            accum += x
            if(accum >= split):
                if(accum != split):
                    return False
                else:
                    accum = 0
                    continue

        return True

    split = FIRST_TRUE(testingP,testTrue,-1)

    amount = (total//split)
    amount = int(round(amount))
    return len(s) - amount





t = readInt()

for i in range(t):
    n = readInt()
    s = readLine()

    result = ask(s)
    print(result)