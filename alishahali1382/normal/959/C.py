n=int(input())

#section 1
if n<6:
    print(-1)
else:
    print(1,2)
    print(1,3)
    print(1,4)
    print(2,5)
    print(2,6)
    for i in range(7,n+1):
        print(1,i)


#section 2
for i in range(2,n+1):
    print(1,i)

"""
1 2
1 3
1 4
2 5
2 6
1 7
1 8

1 2
2 3
3 4
4 5
1 6
1 7
1 8
"""