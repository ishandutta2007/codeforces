ntest = int(input())
while ntest > 0:
    
    n = int(input())
    a = list(map(int, input().split()))
    
    cnt_wrong_odd = 0
    cnt_wrong_even = 0
    
    for i in range(0, len(a)):
        if i % 2 != a[i] % 2:
            if i % 2: 
                cnt_wrong_odd += 1
            else: 
                cnt_wrong_even += 1
                
    if cnt_wrong_odd != cnt_wrong_even: 
        print(-1)
    else: 
        print(cnt_wrong_odd)
        
    ntest -= 1