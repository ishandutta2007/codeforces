rating_steps = [1400, 1600, 1900]

cases = int(input())

while cases > 0:
    cases -= 1
    rating = int(input())

    ans = 4
    for x in rating_steps:
        if x <= rating:
            ans -= 1
    print("Division", ans)