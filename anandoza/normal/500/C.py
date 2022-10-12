n, m = tuple(int(i) for i in raw_input().split())
w = tuple(int(i) for i in raw_input().split())
b = tuple(int(i)-1 for i in raw_input().split())

stack = [b[i] for i in xrange(m) if b[i] not in b[:i]]

ans = 0
#print stack
for j in b:
    i = stack.index(j)
    ans += sum(w[k] for k in stack[:i])
    #print ans
    stack.remove(j)
    stack.insert(0, j)
    #print stack

print ans