h, m = map(int, raw_input().split(':'))
H, M = map(int, raw_input().split(':'))
t = (h - H) * 60 + (m - M)
if t < 0:
    t += 24 * 60
print "%02d:%02d" % (t / 60, t % 60)