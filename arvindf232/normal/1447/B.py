
# start time 9:39
def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

t = readInt()

def ask(st):

    negs = 0
    min = 1000000007
    sum= 0
    for a in st:
        for b in a:
            # print(b)
            if(abs(b) < min):
                min = abs(b)

            sum += abs(b)
            if(b<=0):
                negs += 1

    if(negs % 2 == 0):
        return sum
    else:
        return sum - 2 * min


for _ in range(t):
    a,b = readLine()
    ret = []
    for _ in range(a):
        ret.append(readLine())

    result = ask(ret)
    print(result)