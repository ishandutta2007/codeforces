import sys
input = sys.stdin.readline

def main():
    n, l = map(int, input().split())
    alst = list(map(int, input().split()))
    ll = 0
    rr = n - 1
    l_pos = 0
    r_pos = l
    l_speed = 1
    r_speed = 1
    ans = 0
    while rr >= ll:
        l2 = (alst[ll] - l_pos) * r_speed
        r2 = (r_pos - alst[rr]) * l_speed
        if r2 == l2:
            ans += (alst[ll] - l_pos) / l_speed
            r_pos = alst[rr]
            l_pos = alst[ll]
            r_speed += 1
            l_speed += 1
            rr -= 1
            ll += 1
        elif r2 < l2:
            ans += (r_pos - alst[rr]) / r_speed
            l_pos += (r_pos - alst[rr]) / r_speed * l_speed
            r_pos = alst[rr]
            r_speed += 1
            rr -= 1
        else:
            ans += (alst[ll] - l_pos) / l_speed
            r_pos -= (alst[ll] - l_pos) / l_speed * r_speed
            l_pos = alst[ll]
            l_speed += 1
            ll += 1

    ans += (r_pos - l_pos) / (r_speed + l_speed)
    print(ans)
    
for _ in range(int(input())):
    main()