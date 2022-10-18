for tc in range(int(input())):
    n, k = map(int, input().split(' '))
    arr = list(input())
    nw = 0
    ans = []
    for i in arr:
        if i == '1':
            nw += 1
        else:
            if k >= nw: 
                ans.append('0')
                k -= nw
            else:
                ans.extend(['1']*(nw-k))
                ans.append('0')
                ans.extend(['1']*k)
                nw, k = 0, 0
    ans.extend(['1']*nw)
    print(''.join(ans))