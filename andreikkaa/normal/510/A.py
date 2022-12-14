n, m = map(int, input().split())

for i in range(n):
    if i % 2 == 0:
        print("#" * m)
    elif i % 4 == 1:
        print("." * (m - 1), "#", sep="")
    else:
        print("#", "." * (m - 1), sep="")