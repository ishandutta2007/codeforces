a = input()
h, g = 0, 0
if a[0] == 'a' or a[0] == 'h':
    h = 1
if a[1] == '1' or a[1] == '8':
    g = 1
if h + g == 0:
    print(8)
elif h + g == 1:
    print(5)
else:
    print(3)