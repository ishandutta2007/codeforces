v=zip(*map(lambda x:(x[0]+x[1],x[0]-x[1]),(map(int,raw_input().split()) for _ in range(input()))))
print max(v[0])-min(v[0])+max(v[1])-min(v[1])+4