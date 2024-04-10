"""
Accomplished using the EduTools plugin by JetBrains https://plugins.jetbrains.com/plugin/10081-edutools
"""

def readInt():
    return int(input())

def readLine():
    return [int(s) for s in input().split(" ")]

def readString():
    return input()

def ask(s):
    last = 0
    # print(s)
    # print(s[::-1])
    for c in s[::-1]:
        if(c == ")"):
            last += 1
        else:
            break

    # print(last)
    return len(s) < (2*last)

if __name__ == "__main__":

    t = readInt()
    for _ in range(t):
        g = input()
        s = input()

        result = ask(s)
        # print(result)
        if result:
            print ("Yes")
        else:
            print ("No")
    # Write your solution here
    pass