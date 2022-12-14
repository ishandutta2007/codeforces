p11 = list(map(int, input().split()))
p12 = list(map(int, input().split()))
p21 = list(map(int, input().split()))
p22 = list(map(int, input().split()))

def f(a, b, c, d):
    if a[0] > d[1] and b[1] > c[0]:
        return 1
    if a[0] < d[1] and b[1] < c[0]:
        return 2
    return 0

c1 = f(p11, p12, p21, p22)
c2 = f(p12, p11, p21, p22)
c3 = f(p11, p12, p22, p21)
c4 = f(p12, p11, p22, p21)
#print(c1, c2, c3, c4)
#false - win 1 true - win 2

if ((c1 == 2 or c3 == 2) and (c2 == 2 or c4 == 2)):
    print("Team 2")
elif ((c1 == 1 and c3 == 1) or (c2 == 1 and c4 == 1)):
    print("Team 1")
else:
    print("Draw")