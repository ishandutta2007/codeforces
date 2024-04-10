n = input() 
star = ""
dim = ""
for i in range(0,n):
    star = star + '*'
    dim = dim + 'D'
st = n/2
while st > 0:
    print star[:st]+dim[st:-st]+star[-st:]
    st = st - 1
print dim
st = st + 1
while st <= n/2:
    print star[:st]+dim[st:-st]+star[-st:]
    st = st + 1