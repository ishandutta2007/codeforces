a, b = map(int, input().split())
if a == b:
    a *= 10
    b *= 10
    b += 1
    print(a, b)
elif a + 1 == b:
    print(a, b)
elif a == 9 and b == 1:
    print(a, 10)
else:
  print(-1)