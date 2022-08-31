a = list(map(int,input().split()))
if(a[0] + a[1] == a[2] + a[3]):
    print("YES")
elif(a[0] + a[2] == a[1] + a[3]):
    print("YES")
elif(a[0] + a[3] == a[2] + a[1]):
    print("YES")
elif(a[0] + a[3] + a[2] == a[1]):
    print("YES")
elif(a[0] + a[3] + a[1] == a[2]):
    print("YES")
elif(a[0] == a[3] + a[2] + a[1]):
    print("YES")
elif(a[3] == a[0] + a[2] + a[1]):
    print("YES")
else:
    print("NO")