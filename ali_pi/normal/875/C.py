from collections import defaultdict, deque
def main():
    n,m = map(int, raw_input().split())
    cap = [None]*(m+1)
    same_cap = defaultdict(list)
    q = deque()

    def apply_cap(a, c):
        if cap[a] is not None:
            return cap[a] == c
        q.append((a,c))
        while q:
            b = q.pop()
            if b[1] == c:
                if cap[b[0]] is None:
                    cap[b[0]] = c
                    q.extend(same_cap[b[0]])
                    same_cap[b[0]] = []
                elif cap[b[0]]!=c:
                    return False
        return True
    def same(a,b):
        same_cap[b].append((a,True))
        same_cap[a].append((b,False))
        if cap[a] == False:
            return apply_cap(b, False)
        if cap[b] == True:
            return apply_cap(a, True)
        return True
    def process(p,c):
        lp = p[0]
        lc = c[0]
        for i in range(1, min(lp,lc)+1):
            if p[i]>c[i]:
                return apply_cap(p[i], True) and apply_cap(c[i], False)
            if p[i]<c[i]:
                return same(p[i], c[i])
        return lp<=lc
    p = list(map(int, raw_input().split()))
    for i in range(n-1):
        c = list(map(int, raw_input().split()))
        if not process(p, c):
            print ('No')
            break
        p = c
    else:
        print ('Yes')
        res = []
        for i,b in enumerate(cap):
            if b:
                res.append(i)
        print(len(res))
        print(' '.join(map(str,res)))
main()