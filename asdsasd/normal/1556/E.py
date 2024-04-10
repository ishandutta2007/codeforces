import sys
input = sys.stdin.readline

class SegTree():
    def __init__(self, n, e, ope, lst=[]):
        self.N0 = 2 ** (n - 1).bit_length()
        self.e = e
        self.ope = ope
        self.data = [e] * (2 * self.N0)
        if lst:
            for i in range(n):
                self.data[self.N0 + i] = lst[i]
            for i in range(self.N0 - 1, 0, -1):
                self.data[i] = self.ope(self.data[2 * i], self.data[2 * i + 1])
    
    def f5(self):
        for i in range(self.N0 - 1, 0, -1):
            self.data[i] = self.ope(self.data[2 * i], self.data[2 * i + 1])
                
    def update(self, i, x): #a_ix
        i += self.N0
        self.data[i] = x
        while i > 1:
            i >>= 1
            self.data[i] = self.ope(self.data[2 * i], self.data[2 * i + 1])
    
    def add(self, i, x):
        self.update(i, x + self.get(i))
    
    def query(self, l, r): #[l, r)
        if r <= l:
            return self.e
            
        res = self.e
        l += self.N0
        r += self.N0
        while l < r:
            if l & 1:
                res = self.ope(res, self.data[l])
                l += 1
            if r & 1:
                r -= 1
                res = self.ope(res, self.data[r])
            l >>= 1
            r >>= 1
        return res
            
    
    def get(self, i): #a_i
        return self.data[self.N0 + i]
        
def ope(x, y):
    if x >= y:
        return x
    else:
        return y

def ope2(x, y):
    if x <= y:
        return x
    else:
        return y

def main():
    n, q = map(int, input().split())
    alst = list(map(int, input().split()))
    blst = list(map(int, input().split()))
    cum = [0]
    pos = 0
    i_p = [-1] * n
    bef = alst[0] >= blst[0]
    seg = SegTree(n, 0, ope)
    inf = 10 ** 15
    seg_min = SegTree(n + 1, inf, ope2)
    seg_max = SegTree(n + 1, -inf, ope)
    i_p_min = [0] * n
    i_p_max = [0] * n
    tot = 0
    seg_min.data[seg_min.N0] = 0
    seg_max.data[seg_min.N0] = 0
    for i, (a, b) in enumerate(zip(alst, blst)):
        cum.append(cum[-1] + a - b)
        if not (a >= b) ^ (bef):
            i_p[i] = pos
            i_p_max[pos] = i
        else:
            pos += 1
            i_p[i] = pos
            bef = a >= b
            i_p_min[pos] = i
            i_p_max[pos] = i
        seg.data[seg.N0 + pos] += abs(a - b)
        tot += b - a
        seg_min.data[seg_min.N0 + i + 1] = tot
        seg_max.data[seg_min.N0 + i + 1] = tot
    seg.f5()
    seg_min.f5()
    seg_max.f5()
    for _ in range(q):
        l, r = map(int, input().split())
        if cum[r] - cum[l - 1] != 0:
            print(-1)
            continue
        l -= 1
        r -= 1
        if seg_min.data[seg_min.N0 + l] > seg_min.query(l, r + 1):
            print(-1)
            continue
        print(seg_max.query(l, r + 1) - seg_min.query(l, r + 1))
        continue
        posl = i_p[l]
        posr = i_p[r]
        
        al = abs(cum[l] - cum[i_p_min[posl]])
        ar = abs(cum[i_p_max[posr] + 1] - cum[r + 1])
        
        seg.add(posl, -al)
        seg.add(posr, -ar)
        print(seg.query(posl, posr + 1))
        seg.add(posl, al)
        seg.add(posr, ar)
        
        
    
    
    
for _ in range(1):
    main()