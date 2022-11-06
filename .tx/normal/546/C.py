from collections import deque

n = input()

a = deque(list(map(int, input().split()))[1:])
b = deque(list(map(int, input().split()))[1:])

it = 0

while a and b:
    x = a.popleft()
    y = b.popleft()
    if x > y:
        a.append(y)
        a.append(x)
    else:
        b.append(x)
        b.append(y)

    it += 1
    if it >= 999999:
        break


if not a:
    print(it, 2)
elif not b:
    print(it, 1)
else:
    print(-1)