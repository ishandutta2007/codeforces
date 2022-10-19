from sys import *

input = stdin.readline

class ordered_set():
    def __init__(self, LOG):
        self.LOG = LOG
        self.Sz = (1 << LOG);
        self.fen = [0] * self.Sz

    def update(self, ind, val):
        while (ind < self.Sz):
            self.fen[ind] += val
            ind += ind & (-ind)

    def get(self, ind):
        sum = 0
        while (ind):
            sum += self.fen[ind]
            ind -= ind & (-ind)
        return sum

    def order_of_key(self, x):
        return self.get(x - 1);

    def find_by_order(self, ind):
        ans = 0
        for i in range(self.LOG):
            x = (1 << (self.LOG - i - 1))
            print(x , self.fen[ans + x] , ind);
            if (self.fen[ans + x] <= ind):
                ind -= self.fen[ans + x]
                ans += x
        return ans + 1

    def upper_bound(self, x):
        return self.find_by_order(self.get(x))

    def lower_bound(self, x):
        return self.upper_bound(x - 1);

fen = ordered_set(20);
n = int(input())
A = list(map(int , input().split()));
B = list(map(int , input().split()));
C = [0] * (n * 2);
for i in range(n):
    C[i * 2] = [A[i] - B[i] , (i + 1) * 2];
    C[i * 2 + 1] = [B[i] - A[i] , (i + 1) * 2 + 1]

C.sort(key=lambda x : x[0]);

ans = 0
prv = -1
D = []
for i in C:
    if(i[0] != prv):
        for j in D:
            fen.update(j , 1)
        D = []
    if(i[1] % 2 == 0):
        ans += fen.get(i[1]);
    else:
        D.append(i[1])
    prv = i[0];

print(ans)