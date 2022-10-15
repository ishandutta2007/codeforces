import sys

def make_string(n, s, i):
    r = ['B'] * n
    r[0] = unichr(s[0] + ord('A')) 
    r[n - 1] = unichr(s[1] + ord('A')) 
    j = 0
    if r[0] != 'A':
        j += 1
    if r[n - 1] == 'C' and (n - j) % 2:
        j += 1
    for l in range(i):
        r[j + 2 * l + 0] = 'A'
        r[j + 2 * l + 1] = 'C'
    return ''.join(r)

k, x, n, m = map(int, raw_input().split())
F = [0] * k
F[0] = 1
F[1] = 1
for i in range(2, k):
    F[i] = F[i - 2] + F[i - 1]

for msk in range(3 ** 4):
    L0, R0, L1, R1 = (msk / (3 ** i) % 3  for i in range(4))
    if n == 1 and L0 != R0 or m == 1 and L1 != R1:
        continue
    F0 = max(0, n - (int)(L0 != 0) - (int)(R0 != 2))
    F1 = max(0, m - (int)(L1 != 0) - (int)(R1 != 2))
    for i in range(F0 / 2 + 1):
        L = 0
        R = F1 / 2
        while L <= R:
            j = (L + R) / 2
            f0, f1 = i, j
            l0, r0, l1, r1 = L0, R0, L1, R1
            flg = False
            for l in range(2, k):
                f0, f1 = f1, f0 + f1
                if r0 == 0 and l1 == 2:
                    f1 += 1
                if f1 * F[k - 1 - l] > x:
                    flg = True
                    break
                l0, r0, l1, r1 = l1, r1, l0, r1
            if flg:
                R = j - 1
            elif f1 == x:
                print make_string(n, (L0, R0), i)
                print make_string(m, (L1, R1), j)
                sys.exit(0)
            else:
                L = j + 1
print "Happy new year!"