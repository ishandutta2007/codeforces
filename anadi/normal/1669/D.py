cases = int(input())

while cases > 0:
    cases -= 1

    n = int(input())
    s = input() + "W"

    ans = True
    is_r, is_b = 0, 0

    for c in s:
        if c == "W":
            if is_r + is_b > 0 and is_r * is_b == 0:
                ans = False
            is_r = is_b = 0
        elif c == "R":
            is_r += 1
        elif c == "B":
            is_b += 1
    
    if ans:
        print("YES")
    else:
        print("NO")