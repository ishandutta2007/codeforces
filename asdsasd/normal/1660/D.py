import sys
input = sys.stdin.readline

max_ = l_ = r_ = 0

def main():
    n = int(input())
    A = list(map(int, input().split()))
    global max_, l_, r_
    max_ = 1
    l_ = n
    r_ = 0
    def f(l, r):
        global max_, l_, r_
        if l == r:
            return
        tot = 1
        p = 1
        for i in range(l, r):
            a = A[i]
            if a % 2 == 0:
                tot += p
            if a < 0:
                tot *= -1
                p *= -1
        
        if tot > max_:
            max_ = tot
            l_ = l
            r_ = n - r
        tmp = 1
        p = 1
        for i in range(l, r):
            a = A[i]
            if a % 2 == 0:
                tmp += p
            if a < 0:
                tmp *= -1
                p *= -1
                
            if tmp * tot > 0:
                d = abs(tot - tmp) + 1
                if d > max_:
                    max_ = d
                    l_ = i + 1
                    r_ = n - r
        
        tmp = 1
        p = 1
        for i in range(r - 1, l - 1, -1):
            a = A[i]
            if a % 2 == 0:
                tmp += p
            if a < 0:
                tmp *= -1
                p *= -1
                
            if tmp * tot > 0:
                d = abs(tot - tmp) + 1
                if d > max_:
                    max_ = d
                    l_ = l
                    r_ = n - i
                    
        
    
    zero = [-1]
    for i, a in enumerate(A):
        if a == 0:
            zero.append(i)
    zero.append(n)
    for i in range(len(zero) - 1):
        l = zero[i] + 1
        r = zero[i + 1]
        f(l, r)
    print(l_, r_)
        
    
    
for _ in range(int(input())):
    main()