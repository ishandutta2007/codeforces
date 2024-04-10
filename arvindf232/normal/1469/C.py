def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

def ask(arr,k):


    pLow = arr[0]
    pHigh = arr[0]


    for i in range(len(arr)):

        t = arr[i]

        pLow = pLow - (k - 1)
        pHigh = pHigh + (k - 1)

        if i == len(arr)-1 or i == 0:
            allowLow = t
            allowHigh = t
        else:
            allowLow = t
            allowHigh = t + k - 1

        if( allowLow > pHigh or pLow > allowHigh):
            return False

        pLow = max(allowLow,pLow)
        pHigh = min(allowHigh,pHigh)

        # print(pLow,pHigh)

    return True




t = readInt()
for _ in range(t):
    n,k = readLine()
    arrs = readLine()

    result = ask(arrs,k)

    if(result):
        print("YES")
    else:
        print("NO")