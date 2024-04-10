x,y=map(int,raw_input().split())
print(['No','Yes'][(x,y)==(0,1)or x+2>y>1and(x-y)%2])