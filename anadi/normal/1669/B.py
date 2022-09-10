cases = int(input())

while cases > 0:
    cases -= 1
    
    n = int(input())
    vals = [int(x) for x in input().split()]

    ans = -1
    counter = {}
    for x in vals:
        counter[x] = counter.get(x, 0) + 1
        if counter[x] == 3:
            ans = x
    
    print(ans)