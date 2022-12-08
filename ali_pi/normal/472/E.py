class Board(object):
    def __init__(self, init):
        self.grid = init
    
    moves = []
    
    def current(self):
        return self.moves[-1]
    
    def print_moves(self):
        print(len(self.moves)-1)
        for i,j in self.moves:
            print i+1, j+1
    
    def search(self, value):
        for i in range(len(self.grid)):
            for j in range(len(self.grid[i])):
                if self.grid[i][j] == value: yield [i,j]
    
    def swap(self, x, y):
        olx, oly = self.current()
        if max(abs(x), abs(y)) != 1: print("wrong move")
        self.grid[olx][oly], self.grid[olx+x][oly+y] = self.grid[olx+x][oly+y], self.grid[olx][oly]
        self.moves.append((olx+x,oly+y))

def main():
    n,m = read()
    init = [read() for i in range(n)]
    target = [read() for i in range(n)]
    balls = []
    balls2 = []
    for i in init: balls.extend(i)
    for i in target: balls2.extend(i)
    balls.sort()
    balls2.sort()
    if balls != balls2:
        print(-1)
        return
    transpose = False
    if m == 1:
        balls = []
        for i in init: balls.extend(i)
        init = [balls]
        balls2 = []
        for i in target: balls2.extend(i)
        target = [balls2]
        n,m = m,n
        transpose = True
    if n == 1:
        init = init[0]
        target = target[0]
        removed = -1
        found = -1
        flag = False
        for i in range(m-1):
            if removed == -1 and init[i] != target[i]:
                removed = i
            if removed > -1 and init[i + (1 if found > -1 else 0)] != target[i+1]:
                if found == -1 and init[i] == target[removed]:
                    found = i
                else:
                    flag = True
                    break
        if not flag:
            b = Board([])
            b.moves = [((x, 0) if transpose else (0, x)) for x in range(found, removed-1, -1)]
            b.print_moves()
            return
        removed = -1
        found = -1
        flag = False
        for i in range(m-1):
            if removed == -1 and target[i] != init[i]:
                removed = i
            if removed > -1 and target[i + (1 if found > -1 else 0)] != init[i+1]:
                if found == -1 and target[i] == init[removed]:
                    found = i
                else:
                    flag = True
                    break
        if not flag:
            b = Board([])
            b.moves = [((x, 0) if transpose else (0, x)) for x in range(removed, found+1)]
            b.print_moves()
            return
        print(-1)
        return
    b = Board(init)
    a = next(b.search(target[-1][-1]))
    b.grid[a[0]][a[1]] += 1000
    target[-1][-1] += 1000
    b.moves = [a]
    while b.current()[1]: b.swap(0, -1)
    while b.current()[0]: b.swap(-1, 0)
    for i in range(n-2):
        for j in range(m):
            for pos in b.search(target[i][j]):
                if pos > [i,j]: break
            while b.current()[0] < pos[0]: b.swap(1, 0)
            if pos[1] == j:
                if j < m-1:
                    b.swap(0, 1)
                    b.swap(-1, -1)
                    b.swap(1, 0)
                    pos[1] += 1
                else:
                    b.swap(0, -1)
                    b.swap(-1, 1)
                    b.swap(1, 0)
                    pos[1] -= 1
            if pos[1] > j:
                while b.current()[1] < pos[1]-1: b.swap(0, 1)
                if pos[0] == n-1:
                    b.swap(-1, 1)
                    b.swap(1, 0)
                    b.swap(-1, -1)
                    pos[0] -= 1
                b.swap(1, 1)
                while b.current()[1] > j:
                    b.swap(-1, -1)
                    b.swap(0, 1)
                    b.swap(1, -1)
            elif pos[1] < j:
                while b.current()[1] > pos[1]+1: b.swap(0, -1)
                if pos[0] == n-1:
                    b.swap(-1, -1)
                    b.swap(1, 0)
                    b.swap(-1, 1)
                    pos[0] -= 1
                b.swap(1, -1)
                while b.current()[1] < j:
                    b.swap(-1, 1)
                    b.swap(0, -1)
                    b.swap(1, 1)
            if pos[0] > i and j < m-1:
                b.swap(-1, 1)
                while b.current()[0] > i:
                    b.swap(-1, -1)
                    b.swap(1, 0)
                    b.swap(-1, 1)
                b.swap(1, -1)
            elif pos[0] > i and j == m-1:
                b.swap(-1, -1)
                while b.current()[0] > i:
                    b.swap(-1, 1)
                    b.swap(1, 0)
                    b.swap(-1, -1)
                b.swap(1, 1)
            if j < m-1:
                b.swap(-1, 1)
            else:
                while b.current()[1]: b.swap(0, -1)
    for j in range(m-2):
        for i in [n-2, n-1]:
            for pos in b.search(target[i][j]):
                if pos[0] < n-2: continue
                if i == n-2 and pos[0] == n-1 and pos[1] == j:
                    b.swap(1, 0)
                    break
                if pos[1] > j:
                    while b.current()[1] < pos[1]-1: b.swap(0, 1)
                    if pos[0] == n-2 and i == n-1:
                        b.swap(0, 1)
                        b.swap(-1, 0)
                        b.swap(1, -1)
                        pos[0] = n-1
                    if pos[0] == n-1 and i == n-2:
                        b.swap(0, 1)
                        b.swap(1, 0)
                        b.swap(-1, -1)
                        pos[0] = n-2
                    if i == n-2:
                        b.swap(1, 1)
                        while b.current()[1] > j:
                            b.swap(-1, -1)
                            b.swap(0, 1)
                            b.swap(1, -1)
                    elif i == n-1:
                        b.swap(-1, 1)
                        while b.current()[1] > j:
                            b.swap(1, -1)
                            b.swap(0, 1)
                            b.swap(-1, -1)
                        b.swap(1, 1)
                        b.swap(-1, 0)
                    break
    if b.grid[-2][-1] == target[-2][-2]:
        b.swap(0, 1)
    elif b.grid[-1][-2] == target[-2][-2]:
        b.swap(1, 0)
        b.swap(-1, 1)
    elif b.grid[-1][-1] == target[-2][-2]:
        b.swap(1, 1)
        b.swap(-1, 0)
    if b.grid[-1][-2] == target[-2][-1]:
        b.swap(1, -1)
    elif b.grid[-1][-1] == target[-2][-1]:
        b.swap(1, 0)
        b.swap(0, -1)
    b.swap(0, 1)
    b.print_moves()
def read(mode=2):
    inputs = raw_input().strip()
    if mode == 0: return inputs
    if mode == 1: return inputs.split()
    if mode == 2: return list(map(int, inputs.split()))
def write(s="\n"):
    if s is None: s = ""
    if isinstance(s, list): s = " ".join(map(str, s))
    s = str(s)
    print s;end=""

write(main())