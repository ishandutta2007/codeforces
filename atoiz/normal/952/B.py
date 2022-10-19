import random

a = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
random.shuffle(a)
for i in range (0, len(a)):
    print(a[i])
    x = input()
    if x == 'cool':
        print ('normal')
        exit()
    elif x == 'not bad':
        print ('normal')
        exit()
    elif x == 'don\'t think so':
        print ('normal')
        exit()
    elif x == 'don\'t touch me!':
        print ('normal')
        exit()
    elif x == 'don\'t touch me':
        print ('normal')
        exit()
    elif x == 'terrible':
        print ('grumpy')
        exit()
    elif x == 'worse':
        print ('grumpy')
        exit()
    elif x == 'go die in a hole':
        print ('grumpy')
        exit()
    elif x == 'are you serious':
        print ('grumpy')
        exit()
    elif x == 'are you serious?':
        print ('grumpy')
        exit()
    elif x == 'no way':
        print ('grumpy')
        exit()

print ('normal')