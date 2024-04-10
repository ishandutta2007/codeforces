def calc (x, y, p, q):
    if p == q:
        if x == y:
            return 0
        else:
            return -1
    elif p == 0:
        if x == 0:
            return 0
        else:
            return -1
    elif x * q == y * p:
        return 0
    else:
        ans = 0
        k = 1 << 64
        while k != 0:
            cur = ans + k
            if cur * p - x < 0:
                ans = cur
            elif cur * q - y < cur * p - x:
                ans = cur
            k >>= 1
        ans += 1

        return ans * q - y

def main ():
    testc = int(input())
    for i in range(testc):
        arr = input().split(" ")
        print(calc(int(arr[0]), int(arr[1]), int(arr[2]), int(arr[3])))

main()