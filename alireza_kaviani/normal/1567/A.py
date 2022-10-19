q = int(input())
for _ in range(q):
    n = int(input())
    s = input()
    ans = ""
    for i in s:
        if(i == 'U'):
            print('D' , end = "")
        elif (i == 'D'):
            print('U' , end = "")
        else:
            print(i , end = "")
    print()