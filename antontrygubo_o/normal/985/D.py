# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

from math import *

def check(k, n, H, maxx):
    h = min(k, H)
    h = min(h, maxx)
    summa = 0
    if h%2==k%2:
        c = int((h+k)//2)
        summa += int((c*(c+1))//2)
        summa+=int((c-h)*h+(c-h)*(c-h-1)//2)
    else:
        c = int((h+k-1)//2)
        summa+=int(c*(c+1)//2)
        summa+=int((c+1-h)*h+(c-h)*(c-h+1)//2)
    if summa>=n:
        return True
    else:
        return False

def find(n, H, maxx):
    l = 0
    r = 1000000000000000
    while r-l>1:
        current = int((l+r)//2)
        if check(current, n, H, maxx):
            r = current
        else:
            l = current
    return r


n = int(get_number())
H = int(get_number())
maxx = int((int(sqrt(8*n+1))+1)//2)
print(find(n, H, maxx))