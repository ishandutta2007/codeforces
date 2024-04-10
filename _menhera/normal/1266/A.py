

N = int(input())

for x in range(N):
    a = input()
    s = 0
    for i in a:
        s += int(i)
    
    d4 = False
    for i in range(len(a)):
        for j in range(len(a)):
            if i==j: continue
            if ( int(a[i])*10 + int(a[j]) )%20 == 0:
                d4 = True
    
    if s%3==0 and d4: print('red')
    else:  print('cyan')