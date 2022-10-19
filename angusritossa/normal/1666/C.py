points = []
for i in range(3):
    points.append(list(map(int, input().strip().split())))

mid = [sorted([points[i][0] for i in range(3)])[1], sorted([points[i][1] for i in range(3)])[1]]
out = []
for i in range(3):
    if points[i][0] != mid[0]:
        out.append([points[i][0],points[i][1],mid[0],points[i][1]])
    if points[i][1] != mid[1]:
        out.append([mid[0],points[i][1],mid[0],mid[1]])
print(len(out))
for x in out:
    print(' '.join(list(map(str,x))))