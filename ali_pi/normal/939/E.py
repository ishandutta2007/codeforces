import sys

q = int(raw_input()) - 1
inp = raw_input().split()
x = int(inp[1])
n = 1
h = [x]
s = [x]
f = 0
ptr = 0

def func(arr, sum_arr, ptr, size):
    return arr[size-1] - float(sum_arr[ptr] + arr[size-1])/(ptr+2)

while q > 0:
    q -= 1
    inp = raw_input().split()
    if inp[0] == '1':
        x = int(inp[1])
        s.append(s[n - 1] + x)
        n += 1
        h.append(x)
        if n == 2:
            f = (h[1] - h[0])*0.5
        elif n == 3:
            f1 = (h[2] - s[2]/3.0)
            f2 = (h[2] - h[0])/2.0
            if f1 >= f2:
                ptr = 1
                f = f1
            else:
                ptr = 0
                f = f2
        else:
            while ptr < n-1 and func(h, s, ptr, n) <= func(h, s, ptr+1, n):
                ptr += 1
            f = func(h, s, ptr, n)
    else:
        print f