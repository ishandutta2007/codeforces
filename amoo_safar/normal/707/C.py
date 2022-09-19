n = int(input())
if n < 3:
    print(-1)
else:
    t = 0
    while n > 4 and n% 2 == 0:
        n //= 2
        t += 1
    if n == 4:
        p = 2**t
        print(p*3,p*5)
    else:
        y = n** 2
        p = 2 ** t
        print(p * int(y//2),p * (int(y//2)+1))