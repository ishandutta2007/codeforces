MAX_NUM = 2000000
prime_str = ('2      3      5      7     11     13     17     19     23     29 '
        +   '31     37     41     43     47     53     59     61     67     71 '
        +   '73     79     83     89     97    101    103    107    109    113 '
        +  '127    131    137    139    149    151    157    163    167    173 '
        +  '179    181    191    193    197    199    211    223    227    229 '
        +  '233    239    241    251    257    263    269    271    277    281 '
        +  '283    293    307    311    313    317 '
)
prime_list = [int(p) for p in prime_str.split()]
used = [False] * MAX_NUM
n = input()
a = list(map(int,raw_input().split()))
def record(x):
    t = []
    for p in prime_list:
        if x % p == 0:
            while x % p == 0:
                x = x // p
            t.append(p)
            if x == 1:
                break
    if x != 1:
        t.append(x)

    for ti in t:
        for i in range(ti, MAX_NUM, ti):
            used[i] = True
b = []
for ai in a:
    if not used[ai]:
        b.append(ai)
        record(ai)
    else:
        temp = ai + 1
        while used[temp]:
            temp += 1
        b.append(temp)
        record(temp)
        break
temp = 2
while len(b) < len(a):
    while used[temp]:
        temp += 1
    b.append(temp)
    record(temp)
print(' '.join(str(x) for x in b))