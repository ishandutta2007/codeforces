a, b, p, x = map(int, raw_input().split())
ans = 0
ainv = 1
for i in range(p - 2):
    ainv = (ainv * a) % p
rem = 1
inv = 1
lcm = p * (p - 1)
for n in range(1, p):
    rem = (rem * a) % p
    inv = (inv * ainv) % p
    i0 = min(p, ((n * rem - b) * inv + p) % p)
    n0 = n + i0 * (p - 1)
    ans += max(0, (x - n0 + lcm) // lcm)
print(ans)