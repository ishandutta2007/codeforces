from sys import*
n = int(input())
print('?', '0' * n)
stdout.flush()
cnt1 = int(input())
def ask(a, b):
    print('?', '0' * (a - 1) + '1' * (b - a + 1) + '0' * (n - b))
    stdout.flush()
    return int(input())
pos0, pos1 = 0, 0
left, right = 1, n
while pos0 == 0 or pos1 == 0:
    mid = (left + right) // 2
    diff = ask(left, mid)
    checked = mid - left + 1
    if diff - cnt1 == checked:
        pos0 = left
        left = mid + 1
    elif diff - cnt1 == -checked:
        pos1 = left
        left = mid + 1
    else:
        right = mid
print('!', pos0, pos1)