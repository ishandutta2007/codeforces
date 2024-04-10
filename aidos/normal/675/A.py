a, b, c = map(int, input().split())
if c == 0:
    if a==b:
        print("YES")
    else:
        print('NO')
elif (b-a) % c == 0 and (b-a)//c >= 0:
    print("YES")
else:
    print("NO")