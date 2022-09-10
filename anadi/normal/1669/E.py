cases = int(input())
letters = [chr(ord('a') + i) for i in range(11)]

while cases > 0:
    cases -= 1
    
    n = int(input())
    counter = {}

    for _ in range(n):
        s = input()
        counter[s] = counter.get(s, 0) + 1
    
    ans = 0
    for a in letters:
        for b in letters:
            for c in letters:
                if b == c:
                    continue
                
                ans += counter.get("".join([a, b]), 0) * counter.get("".join([a, c]), 0)
                ans += counter.get("".join([b, a]), 0) * counter.get("".join([c, a]), 0)
    print(ans // 2)