n,k=map(int,input().split())
a=[int(input().replace(" ",""),2) for i in range(n)]

# https://stackoverflow.com/questions/374626/how-can-i-find-all-the-subsets-of-a-set-with-exactly-n-elements
from itertools import chain, combinations

def powerset(iterable):
    xs = list(iterable)
    return chain.from_iterable(combinations(xs,n) for n in range(len(xs)+1))

for s in powerset([x for x in range(1<<k) if x in a]):
    if len(s) == 0: continue
    good = True
    for i in range(k):
        c = [(p >> i) & 1 for p in s]
        if c.count(1) > c.count(0):
            good = False
    if good:
        print("YES")
        exit()

print("NO")