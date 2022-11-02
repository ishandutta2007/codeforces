n, h, a, b, k = map(int, input().split())
for i in range(k):
    fa, ta, fb, tb = map(int, input().split())
    if fa == fb:
        print(abs(ta-tb))
    else:
        if max(ta, tb) < a or min(ta, tb) > b:
            print(min(abs(ta-a) + abs(tb-a), abs(ta-b)+abs(tb-b)) + abs(fa-fb))
        else:
            print(abs(ta-tb) + abs(fa-fb))